#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Это лаба #6
	setlocale(LC_ALL, "");
	float U = 5, R1 = 1000, R2 = 330, C1 = 5, C2 = 2, L1 = 1, L2 = 2, Xc1 = 0, Xc2 = 0, Xl1 = 0, Xl2 = 0, Xc1Xl1 = 0, Xc1Xl1R1 = 0, R2Xc2 = 0, R2Xc2Xl2 = 0, Z = 0;
	float sumI = 0, U1 = 0, U2 = 0, Ic1 = 0, Ir1 = 0, Il1 = 0, Ic2 = 0, Ir2 = 0, Il2 = 0, Pr1 = 0, Pr2 = 0, Qc1 = 0, Qc2 = 0, Ql1 = 0, Ql2 = 0, sumP = 0, sumQ = 0, S = 0;
	const double Pi = 3.14; int n = 0;

	cout << "1) Теоритеческие расчёты. 2) Multisim. 3) Практика."; cin >> n;

	switch (n) {
	case 1: 
		for (int f = 250; f <= 3000; f += 250) {
			Xc1 = 1 / (2 * Pi * f * C1 * pow(10, (-6)) );
			Xc2 = 1 / (2 * Pi * f * C2 * pow(10, (-6)) );
			Xl1 = 2 * Pi * f * L1;
			Xl2 = 2 * Pi * f * L2;
			Xc1Xl1 = (Xc1 * Xl1) / (Xc1 + Xl1);
			Xc1Xl1R1 = (Xc1Xl1 * R1) / (Xc1Xl1 + R1);
			R2Xc2 = (R2 * Xc2) / (R2 + Xc2);
			R2Xc2Xl2 = (R2Xc2 * Xl2) / (R2Xc2 + Xl2);
			Z = Xc1Xl1R1 + R2Xc2Xl2;

			sumI = (U / Z) * 1000; //мА
			U1 = (sumI * Xc1Xl1R1) / 1000; //B
			U2 = (sumI * R2Xc2Xl2) / 1000;

			Ic1 = U1 / Xc1 * 1000; //мА
			Ir1 = U1 / R1 * 1000;
			Il1 = U1 / Xl1 * 1000;
			Ic2 = U2 / Xc2 * 1000;
			Ir2 = U2 / R2 * 1000;
			Il2 = U2 / Xl2 * 1000;
		
			Pr1 = U1 * Ir1; //мВт
			Pr2 = U2 * Ir2;
			Qc1 = U1 * Ic1;
			Qc2 = U2 * Ic2;
			Ql1 = U1 * Il1;
			Ql2 = U2 * Il2;

			sumP = Pr1 + Pr2;
			sumQ = Qc1 + Qc2 + Ql1 + Ql2;
			S = sqrt(pow(sumP, 2) + pow(sumQ, 2));

			cout << "\n" << f << " Гц" << "\n\n";
			cout << "Xc1 = " << Xc1 << " Ом" << "\n";
			cout << "Xc2 = " << Xc2 << " Ом" << "\n";
			cout << "Xl1 = " << Xl1 << " Ом" << "\n";
			cout << "Xl2 = " << Xl2 << " Ом" << "\n";
			cout << "Xc1Xl1 = " << Xc1Xl1 << " Ом" << "\n";
			cout << "Xc1Xl1R1 = " << Xc1Xl1R1 << " Ом" << "\n";
			cout << "R2Xc2 = " << R2Xc2 << " Ом" << "\n";
			cout << "R2Xc2Xl2 = " << R2Xc2Xl2 << " Ом" << "\n";
			cout << "Z = " << Z << " Ом" << "\n";

			cout << "sumI = " << sumI << " мА" << "\n";
			cout << "U1 = " << U1 << " В" << "\n";
			cout << "U2 = " << U2 << " В" << "\n";

			cout << "Ic1 = " << Ic1 << " мА" << "\n";
			cout << "Ir1 = " << Ir1 << " мА" << "\n";
			cout << "Il1 = " << Il1 << " мА" << "\n";
			cout << "Ic2 = " << Ic2 << " мА" << "\n";
			cout << "Ir2 = " << Ir2 << " мА" << "\n";
			cout << "Il2 = " << Il2 << " мА" << "\n";

			cout << "Pr1 = " << Pr1 << " мВт" << "\n";
			cout << "Pr2 = " << Pr2 << " мВт" << "\n";
			cout << "Qc1 = " << Qc1 << " мВт" << "\n";
			cout << "Qc2 = " << Qc2 << " мВт" << "\n";
			cout << "Ql1 = " << Ql1 << " мВт" << "\n";
			cout << "Ql2 = " << Ql2 << " мВт" << "\n";

			cout << "S = " << S << " мВт" << "\n";
		}
		break;
	case 2:
		for (int f = 250; f <= 3000; f += 250) {
			cout << "sumI = "; cin >> sumI; cout << "\n";
			cout << "Ic1 = "; cin >> Ic1; cout << "\n";
			cout << "Il1 = "; cin >> Il1; cout << "\n";
			cout << "Ir1 = "; cin >> Ir1; cout << "\n";
			cout << "U1 = "; cin >> U1; cout << "\n";
			cout << "Ir2 = "; cin >> Ir2; cout << "\n";
			cout << "Ic2 = "; cin >> Ic2; cout << "\n";
			cout << "Il2 = "; cin >> Il2; cout << "\n";
			cout << "U2 = "; cin >> U2; cout << "\n";

			Pr1 = U1 * Ir1; //мВт
			Pr2 = U2 * Ir2;
			Qc1 = U1 * Ic1;
			Qc2 = U2 * Ic2;
			Ql1 = U1 * Il1;
			Ql2 = U2 * Il2;

			sumP = Pr1 + Pr2;
			sumQ = Qc1 + Qc2 + Ql1 + Ql2;
			S = sqrt(pow(sumP, 2) + pow(sumQ, 2));

			cout << "Pr1 = " << Pr1 << " мВт" << "\n";
			cout << "Pr2 = " << Pr2 << " мВт" << "\n";
			cout << "Qc1 = " << Qc1 << " мВт" << "\n";
			cout << "Qc2 = " << Qc2 << " мВт" << "\n";
			cout << "Ql1 = " << Ql1 << " мВт" << "\n";
			cout << "Ql2 = " << Ql2 << " мВт" << "\n";

			cout << "S = " << S << " мВт" << "\n";
			
		}
		break;
	case 3:
		for (int f = 250; f <= 3000; f += 250) {
			cout << "sumI = "; cin >> sumI; cout << "\n";
			cout << "U1 = "; cin >> U1; cout << "\n";
			cout << "U2 = "; cin >> U2; cout << "\n";
			
			Ic1 = U1 / Xc1 * 1000; //мА
			Ir1 = U1 / R1 * 1000;
			Il1 = U1 / Xl1 * 1000;
			Ic2 = U2 / Xc2 * 1000;
			Ir2 = U2 / R2 * 1000;
			Il2 = U2 / Xl2 * 1000;

			Pr1 = U1 * Ir1; //мВт
			Pr2 = U2 * Ir2;
			Qc1 = U1 * Ic1;
			Qc2 = U2 * Ic2;
			Ql1 = U1 * Il1;
			Ql2 = U2 * Il2;

			sumP = Pr1 + Pr2;
			sumQ = Qc1 + Qc2 + Ql1 + Ql2;
			S = sqrt(pow(sumP, 2) + pow(sumQ, 2));

			cout << "Ic1 = " << Ic1 << " мА" << "\n";
			cout << "Ir1 = " << Ir1 << " мА" << "\n";
			cout << "Il1 = " << Il1 << " мА" << "\n";
			cout << "Ic2 = " << Ic2 << " мА" << "\n";
			cout << "Ir2 = " << Ir2 << " мА" << "\n";
			cout << "Il2 = " << Il2 << " мА" << "\n";

			cout << "Pr1 = " << Pr1 << " мВт" << "\n";
			cout << "Pr2 = " << Pr2 << " мВт" << "\n";
			cout << "Qc1 = " << Qc1 << " мВт" << "\n";
			cout << "Qc2 = " << Qc2 << " мВт" << "\n";
			cout << "Ql1 = " << Ql1 << " мВт" << "\n";
			cout << "Ql2 = " << Ql2 << " мВт" << "\n";

			cout << "S = " << S << " мВт" << "\n";
		}
		break;
	default:
		cout << "Овощь, ты до 3 считать не умеешь?";
		break;
	}
}
