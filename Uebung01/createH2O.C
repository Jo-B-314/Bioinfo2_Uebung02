#include <BALL/KERNEL/atom.h>
#include <BALL/KERNEL/bond.h>
#include <BALL/KERNEL/molecule.h>
#include <BALL/KERNEL/PTE.h>
#include <BALL/KERNEL/system.h>


using namespace std;
using namespace BALL;

int main(int argc, char* argv[]) {
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