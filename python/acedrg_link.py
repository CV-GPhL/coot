# 18/3/2018 version 2.3 (acedrg?)

#this could be in coot_gui.py
def fill_option_menu_with_string_options(menu, string_list,
                                         default_option_value):
    for item in string_list:
        menu.append_text(item)
        if (default_option_value == item):
            count = string_list.index(item)
            menu.set_active(count)
            print "setting menu active ", default_option_value, count

def acedrg_link_generation_control_window():

    def delete_event(*args):
        window.destroy()
        return False

    # main body
    window = gtk.Window(gtk.WINDOW_TOPLEVEL)
    vbox = gtk.VBox(False, 4)
    inside_hbox_1 = gtk.HBox(False, 4)
    inside_hbox_2 = gtk.HBox(False, 4)
    inside_hbox_3 = gtk.HBox(False, 4)
    inside_hbox_4 = gtk.HBox(False, 4)
    cancel_hbox = gtk.HBox(False, 2)
    order_label = gtk.Label("  Order: ")
    delete_atom_label = gtk.Label("  Delete Atom: ")
    change_bond_order_label = gtk.Label("  Change Bond Order of the Bond between Atoms")
    delete_bond_label = gtk.Label("  Delete Bond: ")
    other_label = gtk.Label(" from First Residue ")
    to_order_label = gtk.Label(" to order")
    right_space_label = gtk.Label(" ")  # PE hackey
    option_menu_bond_order = gtk.combo_box_new_text()  # for the newly-formed bond
    option_menu_change_bond_order = gtk.combo_box_new_text()  # for a bond already in the ligand
    bond_list = ["Single", "Double"]
    fill_option_menu_with_string_options(option_menu_bond_order,
                                         bond_list,
                                         "Single")
    fill_option_menu_with_string_options(option_menu_change_bond_order,
                                         bond_list,
                                         "Single")
    tt = gtk.Tooltips()
    delete_atom_entry = gtk.Entry()
    delete_bond_entry = gtk.Entry()
    change_bond_order_entry = gtk.Entry()
    h_sep = gtk.HSeparator()
    cancel_button = gtk.Button("  Cancel  ")
    pick_button = gtk.Button("Start (Pick 2 Atoms)...")

    window.set_title("Make a Link using Acedrg and Atom Click Click")
    vbox.pack_start(inside_hbox_1, False, False, 2)
    vbox.pack_start(inside_hbox_2, False, False, 2)
    vbox.pack_start(inside_hbox_3, False, False, 2)
    vbox.pack_start(inside_hbox_4, False, False, 2)
    inside_hbox_1.pack_start(order_label, False, False, 2)
    inside_hbox_1.pack_start(option_menu_bond_order, False, False, 2)
    inside_hbox_2.pack_start(delete_atom_label, False, False, 2)
    inside_hbox_2.pack_start(delete_atom_entry, False, False, 2)
    inside_hbox_2.pack_start(other_label, False, False, 2)
    inside_hbox_3.pack_start(change_bond_order_label, False, False, 2)
    inside_hbox_3.pack_start(change_bond_order_entry, False, False, 2)
    inside_hbox_3.pack_start(to_order_label, False, False, 2)
    inside_hbox_3.pack_start(option_menu_change_bond_order, False, False, 2)
    inside_hbox_3.pack_start(right_space_label, False, False, 2)
    inside_hbox_4.pack_start(delete_bond_label, False, False, 2)
    inside_hbox_4.pack_start(delete_bond_entry, False, False, 2)
    vbox.pack_start(h_sep)
    vbox.pack_start(cancel_hbox, False, False, 6)
    cancel_hbox.pack_start(pick_button, False, False, 6)
    cancel_hbox.pack_start(cancel_button, False, False, 6)
    delete_atom_entry.set_usize(80, -1)
    delete_bond_entry.set_usize(80, -1)
    change_bond_order_entry.set_usize(80, -1)

    tt.set_tip(delete_atom_entry, "Type the atom name to be deleted (leave blank if unsure)")
    tt.set_tip(option_menu_bond_order, "Like a cheeseburger - you can only have single or double")
    tt.set_tip(pick_button, "Click on 2 atoms, Acedrg starts after the second click")
    tt.set_tip(delete_bond_entry, "Delete a bond between atoms (leave blank if unsure)")
    tt.set_tip(change_bond_order_entry, "Change the bond order of the bond between atoms (leave blank if unsure)")

    cancel_button.connect("clicked", delete_event)

    pick_button.connect("clicked", lambda func:
                        click_select_residues_for_acedrg(window,
                                                         option_menu_bond_order,
                                                         delete_atom_entry,
                                                         delete_bond_entry,
                                                         change_bond_order_entry,
                                                         option_menu_change_bond_order))

    window.add(vbox)
    window.show_all()

# hack link cif file so that it works in coot 0.8.9 (:-/)
#
# return the new file name
def hack_link(fn):
    import os
    stub = file_name_sans_extension(fn)
    new_file_name = fn + "-hack.cif"

    with open(fn, "rt") as fin:
        with open(new_file_name, "wt") as fout:
            for line in fin:
                fout.write(line.replace("L-PEPTIDE", "L-peptide"))
    return new_file_name

def click_select_residues_for_acedrg(window, option_menu, delete_atom_entry,
                                     delete_bond_entry, change_bond_order_entry,
                                     change_bond_order_option_menu):

    # return a 3-member list: is-correct atom-name-1 atom-name-2)
    # is-correct can either be
    # True or False or None
    # False  means that there was a blank or empty string
    # True mean we found 2 atom names
    # None  means that we found 1 or 3 or more atom names
    # Typicall this will return [False, "", ""]
    def extract_atom_names_from_string(str_in):
        atom_name_1 = ""
        atom_name_2 = ""
        is_correct = False

        sl = len(str_in)
        if (sl == 0):
            return [is_correct, atom_name_1, atom_name_2]
        else:
            parts = str_in.split("")
            if (not len(parts) == 2):
                return [None, atom_name_1, atom_name_2]  #
            else:
                return [True] + parts

    def make_acedrg_bond(*clicks):
        print "BL DEBUG:: we received these clicks:", clicks

        bond_list = ['single', 'double']
        bond_order = get_option_menu_active_item(option_menu,
                                                 bond_list) # could be enums
        change_bond_order = get_option_menu_active_item(change_bond_order_option_menu,
                                                        bond_list)
        if (len(clicks) == 2):
            click_1 = clicks[0]
            click_2 = clicks[1]
            print "BL DEBUG:: click_1", click_1
            print "BL DEBUG:: click_2", click_2
            if ((len(click_1) == 7) and
                (len(click_2) == 7)):
                resname_1 = residue_name(*click_1[1:5])
                resname_2 = residue_name(*click_2[1:5])
                at_name_1 = click_1[5]
                at_name_2 = click_2[5]
                spec_1 = click_1[1:]
                spec_2 = click_2[1:]
                imol_click_1 = click_1[1]
                imol_click_2 = click_2[1]
                delete_atom_text = delete_atom_entry.get_text()
                delete_bond_entry_text = delete_bond_entry.get_text()
                change_bond_order_entry_text = change_bond_order_entry.get_text()

                if not (isinstance(resname_1, str) and
                        isinstance(resname_2, str)):
                    print "Bad resnames: %s and %s " %(resname_1, resname_2)
                    return False # just in case
                else:
                    if not (imol_click_1 == imol_click_2):
                        add_status_bar_text("These residues are not in the same molecule")
                    else:
                        imol = imol_click_1
                        delete_stripped_1 = delete_atom_text.replace(" ", "")
                        delete_atom_txt = " DELETE ATOM " + delete_stripped_1  + " 1 " \
                                          if len(delete_stripped_1) > 0 else \
                                             ""
                        delete_bond_info = extract_atom_names_from_string(delete_bond_entry_text)
                        change_bond_order_info = extract_atom_names_from_string(change_bond_order_entry_text)
                        s = "LINK:" + \
                            " RES-NAME-1 " + resname_1 + " ATOM-NAME-1 " + at_name_1 + \
                            " RES-NAME-2 " + resname_2 + " ATOM-NAME-2 " + at_name_2
                        # I need to check here if resname_1 or resname_2 came from a file that 
                        # was read into Coot from somewhere other than the refmac monomer library
                        # (that acedrg knows about).

                        cif_fn_1 = cif_file_for_comp_id(resname_1)
                        cif_fn_2 = cif_file_for_comp_id(resname_2)
                        ns = non_standard_residue_names(imol)
                        
                        # if the resnames are not non-standard-residue-names
                        # then we don't need to specify the file - if they
                        # are not, then use cif_fn_1 (or cif_fn_2)
                        
                        print "BL DEBUG:: cif_fn_1:", cif_fn_1
                        print "BL DEBUG:: cif_fn_2:", cif_fn_2
                        print "BL DEBUG:: ns:      ", ns

                        if (bond_order == 'double'):
                            s += " BOND-TYPE DOUBLE"
                        
                        if (resname_1 in ns):
                            s += " FILE-1 " + cif_fn_1
                        if (resname_2 in ns):
                            s += " FILE-2 " + cif_fn_2

                        # delete atom?
                        s += delete_atom_txt

                        # change bond order?
                        if change_bond_order_info[0]:
                            ss = " CHANGE BOND " + \
                                 change_bond_order_info[1] + \
                                 " " + \
                                 change_bond_order_info[2] + \
                                 " " + \
                                 ("DOUBLE" if change_bond_order == 'double' else "SINGLE") + \
                                 " 1 "
                            s += ss

                        # delete bond?
                        if delete_bond_info[0]:
                            ss = " DELETE BOND " + \
                                 delete_bond_info[1] + \
                                 " " + \
                                 delete_bond_info[2] + \
                                 " 1 "
                            s += ss

                        print "BL DEBUG:: LINK string:", s
                        st_1 = "acedrg-link-from-coot-" + \
                               resname_1 + "-" + \
                               resname_2
                        st = st_1 + "-link-instructions"
                        log_file_name = st + ".log"
                        ins_file_name = st + ".txt"

                        # maybe can make a function for call_with_output_file
                        fin = open(ins_file_name, "w")
                        fin.write(s)
                        fin.close()

                        status = popen_command("acedrg",
                                               ["-L", ins_file_name, "-o", st_1],
                                               [],
                                               log_file_name,
                                               False,
                                               local_env=acedrg_env())

                        if not status == 0:
                            m = "WARNING:: acedrg failed.\nSee " + log_file_name
                            info_dialog(m)
                        else:
                            # happy path
                            link_file_name = st_1 + "_link.cif" # acedrg name
                            hack_link_file_name = hack_link(link_file_name)
                            dict_read_status = read_cif_dictionary(hack_link_file_name)
                            # dict_read_status is the number of bonds read
                            if (dict_read_status > -2):
                                make_link(imol_click_1, spec_1, spec_2, "dummy-name", 1.0)
                    window.destroy()  # when?
                    
    user_defined_click(2, make_acedrg_bond)

