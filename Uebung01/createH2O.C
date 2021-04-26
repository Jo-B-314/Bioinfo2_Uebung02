#include <BALL/KERNEL/atom.h>
#include <BALL/KERNEL/bond.h>
#include <BALL/KERNEL/molecule.h>
#include <BALL/KERNEL/PTE.h>
#include <BALL/KERNEL/system.h>


using namespace std;
using namespace BALL;


/**
 * our main can be called ./getSequence -a angle -deg/-rad
 * the last flag specifies whethter your angle is in deg or rad
 * all the parameters are not optional
 * using -h or --help you'll get help
 **/
int main(int argc, char* argv[]) {
	string h = "-h";
	string help = "--help";
	for (int i = 0; i < argc; i++) {
		if (h.compare(argv[i]) == 0 || help.compare(argv[i]) == 0) {
			//-h or --help found
			cout << "Help window:\n-a[angle] : required, angle (H-O-H), you have to specify whether it is in deg or rad\n";
			cout << "-deg/-rad: required, specifies whether your angle is in deg or rad\n";
			cout << "-f/--file[PDB-FILE]: required, .pdb file where you want to store you molecule\n ";
			cout << "-h/--help: open this help window\n";
			return 0;
		}
	}
	if (argc != 6) {
		cerr << "Wrong number of arguments. Use -h or --help to open the help menu.\n";
		return 1;
	}
	double angle;
	bool deg;
	string a = "-a";
	string degstr = "-deg";
	string radstr = "-rad";
	string anglestr;
	string str;
	string file_name;
	string f = "-f";
	string file = "--file";
	for (int i = 0; i < argc; i++) {
		if (!a.compare(argv[i])) {
			if (i+1 >= argc) {
				cerr << "No angle given. Use -h or --help to open the help menu.\n";
				return 1;
			}
			if (!anglestr.empty()) {
				cerr << "More than one angle given. Use -h or --help to open the help menu.\n";
				return 1;
			}
			anglestr = argv[i+1];
			angle = stod(anglestr);
		} 
		if (!degstr.compare(argv[i])) {
			if (!str.empty()) {
				cerr << "More than one angle specification given. Use -h or --help to open the help menu.\n";
				return 1;
			}
			str = argv[i];
			deg = true;
		}
		if (!radstr.compare(argv[i])) {
			if (!str.empty()) {
				cerr << "More than one angle specification given. Use -h or --help to open the help menu.\n";
				return 1;
			}
			str = argv[i];
			deg = false;
		}
		if (!f.compare(argv[i]) || !file.compare(argv[i])) {
			if (!file_name.empty()) {
				cerr << "More than one output file given. Use -h or --help to open the help menu.\n";
				return 1;
			}
			if (i+1 >= argc) {
				cerr << "Flag but no output file given. Use -h or --help to open the help menu.\n";
				return 1;
			}
			file_name = argv[i+1];
		}
	}
	if (str.empty() || anglestr.empty() || file_name.empty()) {
		cerr << "Not all required arguments given. Use -h or --help to open the help menu.\n";
		return 1;
	}
	//b)
	System s;
	Molecule mol;
	s.append(mol);
	//c)
	Atom h1;
	Atom h2;
	Atom o;
	h1.setElement(PTE[Element::H]);
	h2.setElement(PTE[Element::H]);
	o.setElement(PTE[Element::O]);

	h1.setPosition(Vector3(0, 1.42, 0));
	h2.setPosition(Vector3(1.42, 0, 0));
	o.setPosition(Vector3(0, 0, 0));

	Bond* bond1 = h1.createBond(o);
	Bond* bond2 = h2.createBond(o);

	mol.insert(h1);
	mol.insert(h2);
	mol.insert(o);
}