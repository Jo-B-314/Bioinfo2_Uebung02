#include "getSequence.h"

using namespace std;
using namespace BALL;

/**
 * our main can be called ./getSequence -p pdb_datei.pdb
 * this argument is not optional
 * using -h or --help you'll get help
 **/
int main(int argc, char* argv[])
{
	string h = "-h";
	string help = "--help";
	for (int i = 0; i < argc; i++) {
		if (h.compare(argv[i]) == 0 || help.compare(argv[i]) == 0) {
			//-h or --help found
			cout << "Help window:\n-p[PDB FILE] : required, PDB-FILE will be read \n";
			cout << "-h/--help: open this help window\n";
			return 0;
		}
	}
	if (argc != 3) {
		cerr << "Wrong number of arguments. Use -h or --help to open the help menu.\n";
		return 1;
	}
	string p = "-p";
	if (p.compare(argv[1])){
		cerr << "No known flag. Use -h or --help to open the help menu.\n";
		return 1;
	}
	//read the PDB-file into a BALL::System
	PDBFile input(argv[2]);
	System system;
	input >> system;
	
	//we open the fragment data base
	FragmentDB fragment_db("");

	//normalization of atom names
	system.apply(fragment_db.normalize_names);
	system.apply(fragment_db.add_hydrogens);
	system.apply(fragment_db.build_bonds);

	if(system.getProtein(0)) {
		Protein* protein = system.getProtein(0);
		//c)
		c(protein);
		//extension d) number of atoms per chain
		d(protein);
		//extension e) AA sequence of each chain in one and three letter code
		e(system);
		//extension f and g: number of h2o molecules and removal
		System* sys = &system;
		fg(sys);
		//extension h
		task_h(system);
	}
	return 0;
}
