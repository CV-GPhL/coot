/*
 * MoleculesToTriangles/CXXSurface/CXXUtils.h
 *
 * Copyright 2009 by Martin Noble, University of Oxford
 * Author: Martin Noble
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 */
#include <iostream>
#include <iomanip>


#ifndef  __STRING_H
#include <string>
#endif

#ifndef  __MMDB_Manager__
#include"mmdb2/mmdb_manager.h"
#include"mmdb2/mmdb_tables.h"
#endif

#include "CXXChargeTable.h"

using namespace std;

class CXXChargeTable;

namespace CXXUtils{
	
	int assignUnitedAtomRadius(mmdb::Manager*, int selHnd);
	int assignUnitedAtomRadius(mmdb::Manager*);
    double getAtomRadius(mmdb::Manager* theManager, mmdb::Atom* theAtom);
	int assignCharge(mmdb::Manager* theManager, int selHnd, CXXChargeTable *theChargeTable);
	int selectionStringToSelHnd(mmdb::Manager* allAtomsManager_in, std::string selectionString, int existingSelection=-1, mmdb::SELECTION_KEY selKeyRequest=mmdb::SKEY_NEW);
	int unCharge(mmdb::Manager* theManager,int selHnd);
	void reformatAtomRadii();
	
	typedef struct AtomRadius_{
		string atomName;
		string residueName;
		float radius;
	} AtomRadius;
	
	static AtomRadius unitedAtomRadii[] = {
        { " DAM", "DAM", 4.0f},
        { " CA ", "GLY", 2.04f},
        { " CA ", "*  ", 1.99f},
        { " C  ", "*  ", 1.94f},
        { " CB ", "VAL", 1.99f},
        { " CB ", "THR", 1.99f},
        { " CB ", "ILE", 1.99f},
        { " CB ", "ALA", 2.09f},
        { " CB ", "*  ", 2.04f},
        { " CG ", "PRO", 2.04f},
        { " CG ", "MET", 2.04f},
        { " CG ", "LYS", 2.04f},
        { " CG ", "LEU", 1.99f},
        { " CG ", "GLU", 2.04f},
        { " CG ", "GLN", 2.04f},
        { " CG ", "ARG", 2.04f},
        { " CG ", "*  ", 1.94f},
        { " CG1", "VAL", 2.09f},
        { " CG1", "ILE", 2.04f},
        { " CG2", "*  ", 2.09f},
        { " CD ", "PRO", 2.04f},
        { " CD ", "LYS", 2.04f},
        { " CD ", "GLU", 1.94f},
        { " CD ", "GLN", 1.94f},
        { " CD ", "ARG", 2.04f},
        { " CD1", "LEU", 2.09f},
        { " CD1", "ILE", 2.09f},
        { " CD1", "*  ", 1.99f},
        { " CD2", "TRP", 1.94f},
        { " CD2", "LEU", 2.09f},
        { " CD2", "*  ", 1.99f},
        { " CE ", "MET", 2.09f},
        { " CE ", "LYS", 2.04f},
        { " CE1", "TYR", 1.99f},
        { " CE1", "PHE", 1.99f},
        { " CE1", "HIS", 1.99f},
        { " CE2", "TYR", 1.99f},
        { " CE2", "TRP", 1.94f},
        { " CE2", "PHE", 1.99f},
        { " CE3", "TRP", 1.99f},
        { " CZ ", "TYR", 1.94f},
        { " CZ ", "PHE", 1.99f},
        { " CZ ", "ARG", 1.94f},
        { " CZ2", "TRP", 1.99f},
        { " CZ3", "TRP", 1.99f},
        { " CH2", "TRP", 1.99f},
        { " N  ", "VAL", 1.89f},
        { " N  ", "TYR", 1.89f},
        { " N  ", "TRP", 1.89f},
        { " N  ", "THR", 1.89f},
        { " N  ", "SER", 1.89f},
        { " N  ", "PRO", 1.84f},
        { " N  ", "PHE", 1.89f},
        { " N  ", "MET", 1.89f},
        { " N  ", "LYS", 1.89f},
        { " N  ", "LEU", 1.89f},
        { " N  ", "ILE", 1.89f},
        { " N  ", "HIS", 1.89f},
        { " N  ", "GLY", 1.89f},
        { " N  ", "GLU", 1.89f},
        { " N  ", "GLN", 1.89f},
        { " N  ", "CYS", 1.89f},
        { " N  ", "ASP", 1.89f},
        { " N  ", "ASN", 1.89f},
        { " N  ", "ARG", 1.89f},
        { " N  ", "*  ", 1.89f},
        { " ND1", "HIS", 1.89f},
        { " ND2", "ASN", 1.94f},
        { " NE ", "ARG", 1.89f},
        { " NE1", "TRP", 1.89f},
        { " NE2", "HIS", 1.84f},
        { " NE2", "GLN", 1.94f},
        { " NH1", "ARG", 1.94f},
        { " NH2", "ARG", 1.94f},
        { " NZ ", "LYS", 1.99f},
        { " O  ", "*  ", 1.75f},
        { " OG ", "SER", 1.8f},
        { " OG1", "THR", 1.8f},
        { " OD1", "ASP", 1.75f},
        { " OD1", "ASN", 1.75f},
        { " OD2", "ASP", 1.75f},
        { " OE1", "GLU", 1.75f},
        { " OE1", "GLN", 1.75f},
        { " OE2", "GLU", 1.75f},
        { " OH ", "TYR", 1.8f},
        { " SG ", "CYS", 2.12f},
        { " SD ", "MET", 2.07f},
        { " O  ", "WAT", 1.85f},
        { " O  ", "DOD", 1.85f},
        { " O  ", "H2O", 1.85f},
        { " O  ", "HOH", 1.85f},
        { " O  ", "OH2", 1.85f},
        { " OW0", "WAT", 1.85f},
        { " O  ", "WAT", 1.85f},
        { " OH2", "WAT", 1.85f},
        { " OD2", "DOD", 1.85f},
        { " OH2", "H2O", 1.85f},
        { " OH2", "HOH", 1.85f},
        { " OH2", "OH2", 1.85f},
        { " OH2", "WAT", 1.85f},
        { "HG  ", "ASP", 1.6f},
        { "HD2 ", "ASP", 1.6f},
        { "HD1 ", "ASP", 1.6f},
        { "DG  ", "ASP", 1.6f},
        { "DD2 ", "ASP", 1.6f},
        { "DD1 ", "ASP", 1.6f},
        { " AD2", "ASN", 1.94f},
        { " AD1", "ASN", 1.75f},
        { "HG  ", "ASN", 1.6f},
        { "DG  ", "ASN", 1.6f},
        { "HND2", "ASN", 1.2f},
        { "HND1", "ASN", 1.2f},
        { "HD22", "ASN", 1.2f},
        { "HD21", "ASN", 1.2f},
        { "HAD2", "ASN", 1.2f},
        { " #HD2", "ASN", 1.2f},
        { " #DD2", "ASN", 1.2f},
        { "HZ  ", "ARG", 1.6f},
        { "HG2 ", "ARG", 1.6f},
        { "HG1 ", "ARG", 1.6f},
        { "HD2 ", "ARG", 1.6f},
        { "HD1 ", "ARG", 1.6f},
        { "DZ  ", "ARG", 1.6f},
        { " #HG", "ARG", 1.6f},
        { " #HD", "ARG", 1.6f},
        { " #DG", "ARG", 1.6f},
        { " #DD", "ARG", 1.6f},
        { "HNH2", "ARG", 1.2f},
        { "HNH1", "ARG", 1.2f},
        { "HNE ", "ARG", 1.2f},
        { "HN22", "ARG", 1.2f},
        { "HN21", "ARG", 1.2f},
        { "HN12", "ARG", 1.2f},
        { "HN11", "ARG", 1.2f},
        { "HH22", "ARG", 1.2f},
        { "HH21", "ARG", 1.2f},
        { "HH11", "ARG", 1.2f},
        { "HE  ", "ARG", 1.2f},
        { " #HH2", "ARG", 1.2f},
        { " #HH1", "ARG", 1.2f},
        { " #HE", "ARG", 1.2f},
        { " #DH2", "ARG", 1.2f},
        { " #DH1", "ARG", 1.2f},
        { " #DE", "ARG", 1.2f},
        { "HG  ", "CYS", 1.6f},
        { "DG  ", "CYS", 1.6f},
        { "HSG ", "CYS", 1.2f},
        { "HG  ", "CYS", 1.2f},
        { "HG2 ", "GLU", 1.6f},
        { "HG1 ", "GLU", 1.6f},
        { "HE2 ", "GLU", 1.6f},
        { "HE1 ", "GLU", 1.6f},
        { "HD  ", "GLU", 1.6f},
        { "DE2 ", "GLU", 1.6f},
        { "DE1 ", "GLU", 1.6f},
        { "DD  ", "GLU", 1.6f},
        { " #HG", "GLU", 1.6f},
        { " #DG", "GLU", 1.6f},
        { " AE2", "GLN", 1.94f},
        { " AE1", "GLN", 1.75f},
        { "HG2 ", "GLN", 1.6f},
        { "HG1 ", "GLN", 1.6f},
        { "HD  ", "GLN", 1.6f},
        { "DD  ", "GLN", 1.6f},
        { " #HG", "GLN", 1.6f},
        { " #DG", "GLN", 1.6f},
        { "HNE2", "GLN", 1.2f},
        { "HNE1", "GLN", 1.2f},
        { "HE22", "GLN", 1.2f},
        { "HE21", "GLN", 1.2f},
        { "HAE2", "GLN", 1.2f},
        { " #HE2", "GLN", 1.2f},
        { " #DE2", "GLN", 1.2f},
        { "HA2 ", "GLY", 1.6f},
        { "HA1 ", "GLY", 1.6f},
        { " #HA", "GLY", 1.6f},
        { " AE1", "HIS", 1.99f},
        { " AD2", "HIS", 1.99f},
        { " AD1", "HIS", 1.89f},
        { " AE2", "HIS", 1.84f},
        { "HE1 ", "HIS", 1.6f},
        { "HD2 ", "HIS", 1.6f},
        { "DE1 ", "HIS", 1.6f},
        { "DD2 ", "HIS", 1.6f},
        { "HND1", "HIS", 1.2f},
        { "HE2 ", "HIS", 1.2f},
        { "HD1 ", "HIS", 1.2f},
        { "HD1 ", "HIS", 1.2f},
        { "HAD1", "HIS", 1.2f},
        { "DE2 ", "HIS", 1.2f},
        { "DD1 ", "HIS", 1.2f},
        { "HG2 ", "MET", 1.6f},
        { "HG1 ", "MET", 1.6f},
        { "HE3 ", "MET", 1.6f},
        { "HE2 ", "MET", 1.6f},
        { "HE1 ", "MET", 1.6f},
        { " #HG", "MET", 1.6f},
        { " #HE", "MET", 1.6f},
        { " #DG", "MET", 1.6f},
        { " #DE", "MET", 1.6f},
        { "HG2 ", "LYS", 1.6f},
        { "HG1 ", "LYS", 1.6f},
        { "HE2 ", "LYS", 1.6f},
        { "HE1 ", "LYS", 1.6f},
        { "HD2 ", "LYS", 1.6f},
        { "HD1 ", "LYS", 1.6f},
        { " #HG", "LYS", 1.6f},
        { " #HE", "LYS", 1.6f},
        { " #HD", "LYS", 1.6f},
        { " #DG", "LYS", 1.6f},
        { " #DE", "LYS", 1.6f},
        { " #DD", "LYS", 1.6f},
        { "HZ3 ", "LYS", 1.2f},
        { "HZ2 ", "LYS", 1.2f},
        { "HZ1 ", "LYS", 1.2f},
        { "HNZ3", "LYS", 1.2f},
        { "HNZ2", "LYS", 1.2f},
        { "HNZ1", "LYS", 1.2f},
        { "HNZ ", "LYS", 1.2f},
        { " #HZ", "LYS", 1.2f},
        { " #DZ", "LYS", 1.2f},
        { "HG  ", "LEU", 1.6f},
        { "HD6 ", "LEU", 1.6f},
        { "HD5 ", "LEU", 1.6f},
        { "HD4 ", "LEU", 1.6f},
        { "HD3 ", "LEU", 1.6f},
        { "HD2 ", "LEU", 1.6f},
        { "HD1 ", "LEU", 1.6f},
        { "DG  ", "LEU", 1.6f},
        { " #HD2", "LEU", 1.6f},
        { " #HD1", "LEU", 1.6f},
        { " #DD2", "LEU", 1.6f},
        { " #DD1", "LEU", 1.6f},
        { "HG5 ", "ILE", 1.6f},
        { "HG4 ", "ILE", 1.6f},
        { "HG3 ", "ILE", 1.6f},
        { "HG2 ", "ILE", 1.6f},
        { "HG1 ", "ILE", 1.6f},
        { "HD3 ", "ILE", 1.6f},
        { "HD2 ", "ILE", 1.6f},
        { "HD1 ", "ILE", 1.6f},
        { " #HG2", "ILE", 1.6f},
        { " #HG1", "ILE", 1.6f},
        { " #HD1", "ILE", 1.6f},
        { " #DG2", "ILE", 1.6f},
        { " #DG1", "ILE", 1.6f},
        { " #DD1", "ILE", 1.6f},
        { "HG  ", "SER", 1.6f},
        { "DG  ", "SER", 1.6f},
        { "HOG ", "SER", 1.2f},
        { "HG  ", "SER", 1.2f},
        { "HG2 ", "PRO", 1.6f},
        { "HG1 ", "PRO", 1.6f},
        { "HD2 ", "PRO", 1.6f},
        { "HD1 ", "PRO", 1.6f},
        { " #HG", "PRO", 1.6f},
        { " #HD", "PRO", 1.6f},
        { " #DG", "PRO", 1.6f},
        { " #DD", "PRO", 1.6f},
        { "HZ  ", "PHE", 1.6f},
        { "HE2 ", "PHE", 1.6f},
        { "HE1 ", "PHE", 1.6f},
        { "HD2 ", "PHE", 1.6f},
        { "HD1 ", "PHE", 1.6f},
        { "DZ  ", "PHE", 1.6f},
        { "DE2 ", "PHE", 1.6f},
        { "DE1 ", "PHE", 1.6f},
        { "DD2 ", "PHE", 1.6f},
        { "DD1 ", "PHE", 1.6f},
        { "HH  ", "TYR", 1.6f},
        { "HE2 ", "TYR", 1.6f},
        { "HE1 ", "TYR", 1.6f},
        { "HD2 ", "TYR", 1.6f},
        { "HD1 ", "TYR", 1.6f},
        { "DH  ", "TYR", 1.6f},
        { "DE2 ", "TYR", 1.6f},
        { "DE1 ", "TYR", 1.6f},
        { "DD2 ", "TYR", 1.6f},
        { "DD1 ", "TYR", 1.6f},
        { "HOH ", "TYR", 1.2f},
        { "HH  ", "TYR", 1.2f},
        { "HZ2 ", "TRP", 1.6f},
        { "HZ1 ", "TRP", 1.6f},
        { "HH  ", "TRP", 1.6f},
        { "HE  ", "TRP", 1.6f},
        { " #HZ3", "TRP", 1.6f},
        { " #HZ2", "TRP", 1.6f},
        { " #HH2", "TRP", 1.6f},
        { " #HE3", "TRP", 1.6f},
        { " #HD1", "TRP", 1.6f},
        { " #DZ3", "TRP", 1.6f},
        { " #DZ2", "TRP", 1.6f},
        { " #DH2", "TRP", 1.6f},
        { " #DE3", "TRP", 1.6f},
        { " #DD1", "TRP", 1.6f},
        { "HNE1", "TRP", 1.2f},
        { "HNE ", "TRP", 1.2f},
        { "HE1 ", "TRP", 1.2f},
        { " #HE1", "TRP", 1.2f},
        { " #DE1", "TRP", 1.2f},
        { "HG3 ", "THR", 1.6f},
        { "HG2 ", "THR", 1.6f},
        { "HG1 ", "THR", 1.6f},
        { "HB  ", "THR", 1.6f},
        { " #HG2", "THR", 1.6f},
        { " #HG1", "THR", 1.6f},
        { " #DG2", "THR", 1.6f},
        { " #DG1", "THR", 1.6f},
        { "HOG1", "THR", 1.2f},
        { "HOG ", "THR", 1.2f},
        { "HG1 ", "THR", 1.2f},
        { "HG6 ", "VAL", 1.6f},
        { "HG5 ", "VAL", 1.6f},
        { "HG4 ", "VAL", 1.6f},
        { "HG3 ", "VAL", 1.6f},
        { "HG2 ", "VAL", 1.6f},
        { "HG1 ", "VAL", 1.6f},
        { "HB  ", "VAL", 1.6f},
        { " #HG2", "VAL", 1.6f},
        { " #HG1", "VAL", 1.6f},
        { " #DG2", "VAL", 1.6f},
        { " #DG1", "VAL", 1.6f},
        { " CA ", "CBX", 2.09f},
        { " ND1", "HRU", 1.84f},
        { " ND1", "HSD", 1.84f},
        { " ND1", "HSP", 1.89f},
        { " NE2", "HRU", 1.89f},
        { " NE2", "HSD", 1.89f},
        { " NE2", "HSP", 1.89f},
        { " OT2", "CTE", 1.75f},
        { " OT2", "CTR", 1.75f},
        { " CH3", "ACE", 2.09f},
        { " C3 ", "ACE", 2.09f},
        { "HO  ", "WAT", 1.2f},
        { "H2  ", "WAT", 1.2f},
        { "H1  ", "WAT", 1.2f},
        { " CB ", "UNK", 1.94f},
        { " N  ", "UNK", 1.89f},
        { " C6 ", "U  ", 1.99f},
        { " C5 ", "U  ", 1.99f},
        { " C4 ", "U  ", 1.94f},
        { " C2 ", "U  ", 1.94f},
        { " N3 ", "U  ", 1.89f},
        { " N1 ", "U  ", 1.84f},
        { " O4 ", "U  ", 1.75f},
        { " O2 ", "U  ", 1.75f},
        { "HN3 ", "U  ", 1.2f},
        { " C5M", "T  ", 2.09f},
        { " C5A", "T  ", 2.09f},
        { " C6 ", "T  ", 1.99f},
        { " C5 ", "T  ", 1.94f},
        { " C4 ", "T  ", 1.94f},
        { " C2 ", "T  ", 1.94f},
        { " N3 ", "T  ", 1.89f},
        { " N1 ", "T  ", 1.84f},
        { " O4 ", "T  ", 1.75f},
        { " O2 ", "T  ", 1.75f},
        { "HN3 ", "T  ", 1.2f},
        { "HO  ", "OH2", 1.2f},
        { "H2  ", "OH2", 1.2f},
        { "H1  ", "OH2", 1.2f},
        { "HT3 ", "NTR", 1.2f},
        { "HT2 ", "NTR", 1.2f},
        { "HT1 ", "NTR", 1.2f},
        { "HT3 ", "NTE", 1.2f},
        { "HT2 ", "NTE", 1.2f},
        { "HT1 ", "NTE", 1.2f},
        { " C8 ", "NT ", 2.09f},
        { " C14", "NT ", 2.09f},
        { " C2 ", "NT ", 2.04f},
        { " C17", "NT ", 2.04f},
        { " C16", "NT ", 2.04f},
        { " C7 ", "NT ", 1.99f},
        { " C5 ", "NT ", 1.99f},
        { " C13", "NT ", 1.99f},
        { " C11", "NT ", 1.99f},
        { " N9 ", "NT ", 1.94f},
        { " N2 ", "NT ", 1.94f},
        { " N10", "NT ", 1.94f},
        { " N1 ", "NT ", 1.94f},
        { " C9 ", "NT ", 1.94f},
        { " C6 ", "NT ", 1.94f},
        { " C4 ", "NT ", 1.94f},
        { " C3 ", "NT ", 1.94f},
        { " C18", "NT ", 1.94f},
        { " C15", "NT ", 1.94f},
        { " C12", "NT ", 1.94f},
        { " C10", "NT ", 1.94f},
        { " C1 ", "NT ", 1.94f},
        { " N8 ", "NT ", 1.89f},
        { " N6 ", "NT ", 1.89f},
        { " N4 ", "NT ", 1.89f},
        { " N3 ", "NT ", 1.89f},
        { " N7 ", "NT ", 1.84f},
        { " N5 ", "NT ", 1.84f},
        { " O3 ", "NT ", 1.75f},
        { " O2 ", "NT ", 1.75f},
        { " O1 ", "NT ", 1.75f},
        { "HN9 ", "NT ", 1.2f},
        { "HN8 ", "NT ", 1.2f},
        { "HN6 ", "NT ", 1.2f},
        { "HN4 ", "NT ", 1.2f},
        { "HN3 ", "NT ", 1.2f},
        { "HN2 ", "NT ", 1.2f},
        { "HN10", "NT ", 1.2f},
        { "HN1 ", "NT ", 1.2f},
        { " C8 ", "I  ", 1.99f},
        { " C2 ", "I  ", 1.99f},
        { " C6 ", "I  ", 1.94f},
        { " C5 ", "I  ", 1.94f},
        { " C4 ", "I  ", 1.94f},
        { " N1 ", "I  ", 1.89f},
        { " N9 ", "I  ", 1.84f},
        { " N7 ", "I  ", 1.84f},
        { " N3 ", "I  ", 1.84f},
        { " O6 ", "I  ", 1.75f},
        { "HN1 ", "I  ", 1.2f},
        { " CE1", "HSP", 1.99f},
        { " CD2", "HSP", 1.99f},
        { " AE1", "HSP", 1.99f},
        { " AD2", "HSP", 1.99f},
        { " N  ", "HSP", 1.89f},
        { " AE2", "HSP", 1.89f},
        { " AD1", "HSP", 1.89f},
        { "HNE2", "HSP", 1.2f},
        { "HND1", "HSP", 1.2f},
        { "HE2 ", "HSP", 1.2f},
        { "HD1 ", "HSP", 1.2f},
        { "HAE2", "HSP", 1.2f},
        { "HAD1", "HSP", 1.2f},
        { " CE1", "HSD", 1.99f},
        { " CD2", "HSD", 1.99f},
        { " AE1", "HSD", 1.99f},
        { " AD2", "HSD", 1.99f},
        { " N  ", "HSD", 1.89f},
        { " AE2", "HSD", 1.89f},
        { " AD1", "HSD", 1.84f},
        { "HNE2", "HSD", 1.2f},
        { "HE2 ", "HSD", 1.2f},
        { "HAE2", "HSD", 1.2f},
        { " RU ", "HRU", 2.27f},
        { " N5 ", "HRU", 1.99f},
        { " N4 ", "HRU", 1.99f},
        { " N3 ", "HRU", 1.99f},
        { " N2 ", "HRU", 1.99f},
        { " N1 ", "HRU", 1.99f},
        { " CE1", "HRU", 1.99f},
        { " CD2", "HRU", 1.99f},
        { " N  ", "HRU", 1.89f},
        { "HO  ", "HOH", 1.2f},
        { "H2  ", "HOH", 1.2f},
        { "H1  ", "HOH", 1.2f},
        { " FE ", "HEM", 2.27f},
        { " CMD", "HEM", 2.09f},
        { " CMC", "HEM", 2.09f},
        { " CMB", "HEM", 2.09f},
        { " CMA", "HEM", 2.09f},
        { " CBD", "HEM", 2.04f},
        { " CBC", "HEM", 2.04f},
        { " CBB", "HEM", 2.04f},
        { " CBA", "HEM", 2.04f},
        { " CAD", "HEM", 2.04f},
        { " CAA", "HEM", 2.04f},
        { " CHD", "HEM", 1.99f},
        { " CHC", "HEM", 1.99f},
        { " CHB", "HEM", 1.99f},
        { " CHA", "HEM", 1.99f},
        { " CAC", "HEM", 1.99f},
        { " CAB", "HEM", 1.99f},
        { " CGD", "HEM", 1.94f},
        { " CGA", "HEM", 1.94f},
        { " C4D", "HEM", 1.94f},
        { " C4C", "HEM", 1.94f},
        { " C4B", "HEM", 1.94f},
        { " C4A", "HEM", 1.94f},
        { " C3D", "HEM", 1.94f},
        { " C3C", "HEM", 1.94f},
        { " C3B", "HEM", 1.94f},
        { " C3A", "HEM", 1.94f},
        { " C2D", "HEM", 1.94f},
        { " C2C", "HEM", 1.94f},
        { " C2B", "HEM", 1.94f},
        { " C2A", "HEM", 1.94f},
        { " C1D", "HEM", 1.94f},
        { " C1C", "HEM", 1.94f},
        { " C1B", "HEM", 1.94f},
        { " C1A", "HEM", 1.94f},
        { " N_D", "HEM", 1.84f},
        { " N_C", "HEM", 1.84f},
        { " N_B", "HEM", 1.84f},
        { " N_A", "HEM", 1.84f},
        { " O2D", "HEM", 1.75f},
        { " O2A", "HEM", 1.75f},
        { " O1D", "HEM", 1.75f},
        { " O1A", "HEM", 1.75f},
        { "HO  ", "H2O", 1.2f},
        { "H2  ", "H2O", 1.2f},
        { "H1  ", "H2O", 1.2f},
        { " C8 ", "G  ", 1.99f},
        { " N2 ", "G  ", 1.94f},
        { " C6 ", "G  ", 1.94f},
        { " C5 ", "G  ", 1.94f},
        { " C4 ", "G  ", 1.94f},
        { " C2 ", "G  ", 1.94f},
        { " N1 ", "G  ", 1.89f},
        { " N9 ", "G  ", 1.84f},
        { " N7 ", "G  ", 1.84f},
        { " N3 ", "G  ", 1.84f},
        { " O6 ", "G  ", 1.75f},
        { "HN2 ", "G  ", 1.2f},
        { "HN1 ", "G  ", 1.2f},
        { "DO  ", "DOD", 1.2f},
        { "D2  ", "DOD", 1.2f},
        { "D1  ", "DOD", 1.2f},
        { " OXT", "CTE", 1.75f},
        { " N  ", "CBX", 1.89f},
        { "HN  ", "CBX", 1.2f},
        { "H   ", "CBX", 1.2f},
        { " C6 ", "C  ", 1.99f},
        { " C5 ", "C  ", 1.99f},
        { " N4 ", "C  ", 1.94f},
        { " C4 ", "C  ", 1.94f},
        { " C2 ", "C  ", 1.94f},
        { " N3 ", "C  ", 1.84f},
        { " N1 ", "C  ", 1.84f},
        { " O2 ", "C  ", 1.75f},
        { "HN4 ", "C  ", 1.2f},
        { "HN3 ", "C  ", 1.2f},
        { " BR ", "BR ", 2.1f},
        { " C8 ", "A  ", 1.99f},
        { " C2 ", "A  ", 1.99f},
        { " N6 ", "A  ", 1.94f},
        { " C6 ", "A  ", 1.94f},
        { " C5 ", "A  ", 1.94f},
        { " C4 ", "A  ", 1.94f},
        { " N9 ", "A  ", 1.84f},
        { " N7 ", "A  ", 1.84f},
        { " N3 ", "A  ", 1.84f},
        { " N1 ", "A  ", 1.84f},
        { "HN6 ", "A  ", 1.2f},
        { " C5M", "5MU", 2.09f},
        { " C5A", "5MU", 2.09f},
        { " C6 ", "5MU", 1.99f},
        { " C5 ", "5MU", 1.94f},
        { " C4 ", "5MU", 1.94f},
        { " C2 ", "5MU", 1.94f},
        { " N3 ", "5MU", 1.89f},
        { " N1 ", "5MU", 1.84f},
        { " O4 ", "5MU", 1.75f},
        { " O2 ", "5MU", 1.75f},
        { "HN3 ", "5MU", 1.2f},
        { " Al6", "*  ", 2.3f},
        { " Al3", "*  ", 2.3f},
        { " Zn ", "*  ", 2.27f},
        { "Ti  ", "*  ", 2.27f},
        { " Ru ", "*  ", 2.27f},
        { " Fe ", "*  ", 2.27f},
        { " Si3", "*  ", 2.21f},
        { " P_3", "*  ", 2.14f},
        { " P  ", "*  ", 2.14f},
        { " S_31", "*  ", 2.12f},
        { " Br ", "*  ", 2.1f},
        { " C_33", "*  ", 2.09f},
        { " S_3", "*  ", 2.07f},
        { " C_R2", "*  ", 2.04f},
        { " C_32", "*  ", 2.04f},
        { " C_22", "*  ", 2.04f},
        { " C5'", "*  ", 2.04f},
        { " C2'", "*  ", 2.04f},
        { " N_33", "*  ", 1.99f},
        { " C_R1", "*  ", 1.99f},
        { " C_31", "*  ", 1.99f},
        { " C_21", "*  ", 1.99f},
        { " C_11", "*  ", 1.99f},
        { " C4'", "*  ", 1.99f},
        { " C3'", "*  ", 1.99f},
        { " C1'", "*  ", 1.99f},
        { " Cl ", "*  ", 1.95f},
        { " N_R2", "*  ", 1.94f},
        { " N_32", "*  ", 1.94f},
        { " N_22", "*  ", 1.94f},
        { " C_R", "*  ", 1.94f},
        { " C_3", "*  ", 1.94f},
        { " C_2", "*  ", 1.94f},
        { " C_1", "*  ", 1.94f},
        { " N_R1", "*  ", 1.89f},
        { " N_31", "*  ", 1.89f},
        { " N_21", "*  ", 1.89f},
        { " O_32", "*  ", 1.85f},
        { " N_R", "*  ", 1.84f},
        { " N_3", "*  ", 1.84f},
        { " N_2", "*  ", 1.84f},
        { " N_1", "*  ", 1.84f},
        { " O_R1", "*  ", 1.8f},
        { " O_31", "*  ", 1.8f},
        { " O2'", "*  ", 1.8f},
        { " O_R", "*  ", 1.75f},
        { " O_4", "*  ", 1.75f},
        { " O_3", "*  ", 1.75f},
        { " O_2", "*  ", 1.75f},
        { " OXT", "*  ", 1.75f},
        { " O5'", "*  ", 1.75f},
        { " O4'", "*  ", 1.75f},
        { " O3'", "*  ", 1.75f},
        { " O2P", "*  ", 1.75f},
        { " O1P", "*  ", 1.75f},
        { " Mn ", "*  ", 1.73f},
        { " Ca ", "*  ", 1.73f},
        { " F_ ", "*  ", 1.64f},
        { "H_  ", "*  ", 1.6f},
        { "HB3 ", "*  ", 1.6f},
        { "HB2 ", "*  ", 1.6f},
        { "HB1 ", "*  ", 1.6f},
        { "HA  ", "*  ", 1.6f},
        { "DA  ", "*  ", 1.6f},
        { " #HB", "*  ", 1.6f},
        { " #DB", "*  ", 1.6f},
        { " Na ", "*  ", 1.57f},
        { "H___", "*  ", 1.2f},
        { "HO5'", "*  ", 1.2f},
        { "HO3'", "*  ", 1.2f},
        { "HO2'", "*  ", 1.2f},
        { "HN  ", "*  ", 1.2f},
        { "H   ", "*  ", 1.2f},
        { " #H ", "*  ", 1.2f},
        { " #D ", "*  ", 1.2f},
        { " C* ", "*  ", 2.0f},
        { " O* ", "*  ", 1.8f},
        { " N* ", "*  ", 1.99f},
        { " S* ", "*  ", 2.12f},
        { " P* ", "*  ", 2.14f}		
	};
	static int nAtomRadii = sizeof(unitedAtomRadii) / sizeof(AtomRadius);
}

