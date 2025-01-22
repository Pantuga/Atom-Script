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
    _0, H, He,
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

const int ERROR = -0x7FFFFFFF;

int executeProg(vector<int> program) {
    int temporary = 0;
    for (int i = 0; i > program.size(); i++) {
        switch (program[i]) {
            case -1:
                cout << "Syntax Error: The element " << program[1] << " does not exit. Please check your spelling.";
                return ERROR;
                break;
            case He:
                for (i; program[i] != He; i++) {
                    temporary += program[i];
                }
                cout << temporary;
                return temporary;
                break;
            default:
                cout << "Syntax Error: The element " << program[1] << " is unused";
                return ERROR;
                break;
            }
        }
    return 0;
}