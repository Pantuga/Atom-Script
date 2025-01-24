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

int execute(vector<int> program) {
    // where variables are stored
    vector<int> intMemory = {0};
    vector<bool> boolMemory = {false};
    vector<string> strMemory = {""};
    // position of the vectors to be read
    int privateMemory;
    int iterator = 0;

    const int READ_DEFAULT = -1;
    int readMode = READ_DEFAULT; // -1 is default
    for (int i = 0; i < program.size(); i++) {
        switch (readMode) {
        case READ_DEFAULT:
            switch (program[i]) { // Other syntax errors are handeled by the reader

            case H: // adds intMemory to strMemory as a character
                strMemory[iterator] += (char)intMemory[iterator];
                break;

            case He: //() sets intMemory to the value inside
                intMemory[iterator] = 0;
                readMode = He;
                break;
            
            case Ne: //() "He [...] He H" withput altering intMemory
                privateMemory = intMemory[iterator];
                readMode = Ne;
                break;

            case Li: // increments iterator by 1
                iterator += 1;
                break;

            case Be: // decrements iterator by 1
                iterator -= 1;
                break;

            case Na: //() sets iterator to the value inside
                iterator = 0;
                readMode = Na;
                break;

            case Mg: // sets iterator to 0
                iterator = 0;
                break;

            case K: //() increments iterator by value inside
                privateMemory = iterator;
                readMode = K;
                break;

            case Ca: //() decrements iterator by value inside
                privateMemory = iterator;
                readMode = Ca;
                break;

            case C: // prints strMemory
                cout << strMemory[iterator];
                break;
            
            case O: // asks for input, stores it in strMemory
                cin >> strMemory[iterator];
                break;

            default:
                cout << "\n Syntax Error: The element " << program[i] << " is unused";
                return -2;
                break;
            }
            break;

        case He:
            if (program[i] != He) {
                intMemory[iterator] += program[i];
            } else if (intMemory[iterator] != 0) {
                readMode = READ_DEFAULT;
            }
            break;

        case Ne:
            if (program[i] != Ne) {
                intMemory[iterator] += program[i];
            } else if (intMemory[iterator] != privateMemory) {
                strMemory[iterator] += (char)intMemory[iterator];
                intMemory[iterator] = privateMemory;
                readMode = READ_DEFAULT;
            }
            break;

        case Na:
            if (program[i] != Na) {
                iterator += program[i];
            } else if (iterator != 0) {
                readMode = READ_DEFAULT;
            }
            break;

        case K:
            if (program[i] != K) {
                iterator += program[i];
            } else if (iterator != privateMemory) {
                readMode = READ_DEFAULT;
            }
            break;

        case Ca:
            if (program[i] != Ca) {
                iterator -= program[i];
            } else if (iterator != privateMemory) {
                readMode = READ_DEFAULT;
            }
            break;
        default:
            cout << "Code Error: " << readMode << endl << "Please report to github";
        }
    }
    return 0;
}