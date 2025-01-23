#include "iostream"
#include "vector"
#include "array"
using namespace std;

const array<string, 119> elements = {
    "", "H", "He",
    "Li", "Be", 
    "B", "C", "N", "O", "F", "Ne",
    "Na", "Mg",
    "Al", "Si", "P", "S", "Cl", "Ar",
    "K", "Ca",
    "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
    "Ga", "Ge", "As", "Se", "Br", "Kr",
    "Rb", "Sr",
    "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd",
    "In", "Sn", "Sb", "Te", "I", "Xe",
    "Cs", "Ba",
    "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
    "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
    "Tl", "Pb", "Bi", "Po", "At", "Rn",
    "Fr", "Ra",
    "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr",
    "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn",
    "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
};

enum ElementsIndex {
    NONE, H, He,
    Li, Be,
    B,  C,  N,  O,  F,  Ne,
    Na, Mg,
    Al, Si, P,  S,  Cl, Ar,
    K,  Ca,
    Sc, Ti, V,  Cr, Mn, Fe, Co, Ni, Cu, Zn,
    Ga, Ge, As, Se, Br, Kr,
    Rb, Sr,
    Y,  Zr, Nb, Mo, Tc, Ru, Rh, Pd, Ag, Cd,
    In, Sn, Sb, Te, I,  Xe,
    Cs, Ba,
    La, Ce, Pr, Nd, Pm, Sm, Eu, Gd, Tb, Dy, Ho, Er, Tm, Yb,
    Lu, Hf, Ta, W,  Re, Os, Ir, Pt, Au, Hg,
    Tl, Pb, Bi, Po, At, Rn,
    Fr, Ra,
    Ac, Th, Pa, U,  Np, Pu, Am, Cm, Bk, Cf, Es, Fm, Md, No, Lr,
    Rf, Db, Sg, Bh, Hs, Mt, Ds, Rg, Cn,
    Nh, Fl, Mc, Lv, Ts, Og,
};

int executeProg(vector<int> program) {
    int temporary = 0;
    const int READ_DEFAULT = -1;
    int readMode = READ_DEFAULT; // -1 is default
    for (int i = 0; i < program.size(); i++) {
        switch (readMode) {
        case -1:
            switch (program[i]) {
            case -1:
                cout << "\n Syntax Error: The element " << program[i] << " does not exit. Please check your spelling.";
                return -1;
                break;
            case He:
                readMode = He;
                break;
            default:
                cout << "\n Syntax Error: The element " << program[i] << " is unused";
                return -2;
                break;
            }
            break;
        case He:
            if (program[i] != He) {
                temporary += program[i];
            } else if (temporary != 0) {
                cout << temporary << endl;
                temporary = 0;
                readMode = 0;
            }
            break;
        default:
            cout << "Code Error:\n" << readMode << "; " << temporary;
        }
    }
    return 0;
}