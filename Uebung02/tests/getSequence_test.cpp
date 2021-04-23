#include <gtest/gtest.h>

#include <BALL/KERNEL/protein.h>
#include <BALL/KERNEL/PTE.h>
#include <BALL/KERNEL/system.h>
#include <BALL/STRUCTURE/peptideBuilder.h>
#include <vector>

#include <getSequence.h>

using namespace BALL;
using namespace std;

TEST(getSequence, oneletter)
{
	vector<Peptides::AminoAcidDescriptor> descriptor_sequence;
	Peptides::AminoAcidDescriptor* aad = new Peptides::AminoAcidDescriptor;
	aad->setAminoAcidType("GLY");
	descriptor_sequence.push_back(*aad);
	Peptides::PeptideBuilder* pb = new Peptides::PeptideBuilder(descriptor_sequence);
    FragmentDB fdb("");
    pb->setFragmentDB(&fdb);
	Protein* protein = pb->construct();

	int str = c(protein);
	ASSERT_EQ(1, str);
}
/*
	Atom a;
	a.setElement(PTE[Element::C]);
	Molecule mol;
	mol.insert(a);

	Protein protein;
	protein.insert(mol);
	*/