#include <iostream>
#include <complex>
#include <cmath>

int sign(double n) {
    if (n > 0.0) {
        return 1;
    } else if (n < 0.0) {
        return -1;
    } else {
        return 0;
    }
}

void SolveEquation(double a, double b, double c, double d) {
    if (a == 0.0) {
        if (b == 0.0) {
            if (c == 0.0) {
                if (d == 0.0) {
                    // 0 = 0
                    std::cout << "The equation has infinite solutions" << std::endl;
                } else {
                    // d = 0, d != 0
                    std::cout << "The equation has no solutions" << std::endl;
                }
            } else {
                // cx + d = 0
                std::cout << "The equation has 1 solutions" << std::endl;
                std::cout << "x = " << -d / c << std::endl;
            }
        } else {
            // bx^2 + cx + d = 0
            double D = c * c - 4.0 * b * d;
            if (D < 0.0) {
                const std::complex<double> i = std::complex<double>(0.0, 1.0);
                std::cout << "The equation has 2 complex solutions" << std::endl;
                const std::complex<double> x1 = -c / (2.0 * b) + sqrt(-D) * i / (2.0 * b);
                const std::complex<double> x2 = -c / (2.0 * b) - sqrt(-D) * i / (2.0 * b);
                std::cout << "x1 = ";
                if (x1.real() != 0.0) {
                    std::cout << x1.real() << " ";
                }
                if (sign(x1.imag()) == -1) {
                    std::cout << "- ";
                } else {
                    std::cout << "+ ";
                }
                if (x1.imag() != 1.0) {
                    std::cout << fabs(x1.imag());
                }
                std::cout << "i" << std::endl;
                std::cout << "x2 = ";
                if (x2.real() != 0.0) {
                    std::cout << x2.real() << " ";
                }
                if (sign(x2.imag() == -1)) {
                    std::cout << "- ";
                } else {
                    std::cout << "+ ";
                }
                if (x2.imag() != 1.0) {
                    std::cout << fabs(x2.imag());
                }
                std::cout << "i" << std::endl;
            } else if (D == 0.0) {
                std::cout << "The equation has 1 solutions" << std::endl;
                std::cout << "x = " << -c / (2.0 * b) << std::endl;
            } else {
                std::cout << "The equation has 2 solutions" << std::endl;
                std::cout << "x1 = " << (-c + sqrt(D)) / (2.0 * b) << std::endl;
                std::cout << "x2 = " << (-c - sqrt(D)) / (2.0 * b) << std::endl;
            }
        }
    } else {
        // ax^3 + bx^2 + cx + d = 0
        b /= a, c /= a, d /= a;
        const double Q = (b * b - 3.0 * c) / 9.0;
        const double R = (2.0 * b * b * b - 9.0 * b * c + 27.0 * d) / 54.0;
        const double S = Q * Q * Q - R * R;
        if (S > 0.0) {
            const double f = acos(R / sqrt(Q * Q * Q)) / 3.0;
            std::cout << "The equation has 3 solutions" << std::endl;
            std::cout << "x1 = " << -2.0 * sqrt(Q) * cos(f) - b / 3.0 << std::endl;
            std::cout << "x2 = " << -2.0 * sqrt(Q) * cos(f + 2 * M_PI / 3.0) - b / 3.0 << std::endl;
            std::cout << "x3 = " << -2.0 * sqrt(Q) * cos(f - 2 * M_PI / 3.0) - b / 3.0 << std::endl;
        } else if (S == 0.0) {
            std::cout << "The equation has < 3 differing solution" << std::endl;
            std::cout << "x1 = " << -2.0 * sign(R) * sqrt(Q) - b / 3.0 << std::endl;
            std::cout << "x2 = " << sign(R) * sqrt(Q) - b / 3.0 << std::endl;
        } else {
            std::cout << "The equation has 1 real solution and 2 complex solutions" << std::endl;
            const std::complex<double> i = std::complex<double>(0.0, 1.0);
            if (Q > 0.0) {
                const double f = acosh(fabs(R) / sqrt(Q * Q * Q)) / 3.0;
                std::cout << "x1 = " << -2.0 * sign(R) * sqrt(Q) * cosh(f) - b / 3.0 << std::endl;
                const std::complex<double> x2 = sign(R) * sqrt(Q) * cosh(f) - b / 3.0 + i * sqrt(3.0) * sqrt(Q) * sinh(f);
                const std::complex<double> x3 = sign(R) * sqrt(Q) * cosh(f) - b / 3.0 - i * sqrt(3.0) * sqrt(Q) * sinh(f);
                std::cout << "x2 = ";
                if (x2.real() != 0.0) {
                    std::cout << x2.real() << " ";
                }
                if (sign(x2.imag()) == -1 && x2.real() != 0.0) {
                    std::cout << "- ";
                } else if (sign(x2.imag()) == 1 && x2.real() != 0.0) {
                    std::cout << "+ ";
                }
                if (x2.imag() != 1.0) {
                    std::cout << fabs(x2.imag());
                }
                std::cout << "i" << std::endl;
                std::cout << "x3 = ";
                if (x3.real() != 0.0) {
                    std::cout << x3.real() << " ";
                }
                if (sign(x3.imag()) == -1 && x2.real() != 0.0) {
                    std::cout << "- ";
                } else if (sign(x3.imag()) == 1 && x2.real() != 0.0) {
                    std::cout << "+ ";
                }
                if (x3.imag() != 1.0) {
                    std::cout << fabs(x3.imag());
                }
                std::cout << "i" << std::endl;
            } else if (Q < 0.0) {
                const double f = asinh(fabs(R) / sqrt(fabs(Q) * fabs(Q) * fabs(Q))) / 3.0;
                std::cout << "x1 = " << -2.0 * sign(R) * sqrt(fabs(Q)) * sinh(f) - b / 3.0 << std::endl;
                const std::complex<double> x2 = sign(R) * sqrt(fabs(Q)) * sinh(f) - b / 3.0 + i * sqrt(3.0) * sqrt(fabs(Q)) * cosh(f);
                const std::complex<double> x3 = sign(R) * sqrt(fabs(Q)) * sinh(f) - b / 3.0 - i * sqrt(3.0) * sqrt(fabs(Q)) * cosh(f);
                std::cout << "x2 = ";
                if (x2.real() != 0.0) {
                    std::cout << x2.real() << " ";
                }
                if (sign(x2.imag()) == -1 && x2.real() != 0.0) {
                    std::cout << "- ";
                } else if (sign(x2.imag()) == 1 && x2.real() != 0.0) {
                    std::cout << "+ ";
                }
                if (x2.imag() != 1.0) {
                    std::cout << fabs(x2.imag());
                }
                std::cout << "i" << std::endl;
                std::cout << "x3 = ";
                if (x3.real() != 0.0) {
                    std::cout << x3.real() << " ";
                }
                if (sign(x3.imag()) == -1 && x2.real() != 0.0) {
                    std::cout << "- ";
                } else if (sign(x3.imag()) == 1 && x2.real() != 0.0) {
                    std::cout << "+ ";
                }
                if (x3.imag() != 1.0) {
                    std::cout << fabs(x3.imag());
                }
                std::cout << "i" << std::endl;
            } else {
                const double x1 = cbrt(d - b * b * b / 27.0) - b / 3.0;
                std::cout << "x1 = " << x1 << std::endl;
                const std::complex<double> x2 = -(b + x1) / 2.0 + i / 2.0 * sqrt(fabs((b - 3.0 * x1) * (b + x1) - 4.0 * c));
                const std::complex<double> x3 = -(b + x1) / 2.0 - i / 2.0 * sqrt(fabs((b - 3.0 * x1) * (b + x1) - 4.0 * c));
                if (x2.real() != 0.0) {
                    std::cout << x2.real() << " ";
                }
                if (sign(x2.imag()) == -1 && x2.real() != 0.0) {
                    std::cout << "- ";
                } else if (sign(x2.imag()) == 1 && x2.real() != 0.0) {
                    std::cout << "+ ";
                }
                if (x2.imag() != 1.0) {
                    std::cout << fabs(x2.imag());
                }
                std::cout << "i" << std::endl;
                std::cout << "x3 = ";
                if (x3.real() != 0.0) {
                    std::cout << x3.real() << " ";
                }
                if (sign(x3.imag()) == -1 && x2.real() != 0.0) {
                    std::cout << "- ";
                } else if (sign(x3.imag()) == 1 && x2.real() != 0.0) {
                    std::cout << "+ ";
                }
                if (x3.imag() != 1.0) {
                    std::cout << fabs(x3.imag());
                }
                std::cout << "i" << std::endl;
            }
        }
    }
}

void Program() {
    std::cout << "Enter an equation in the form of 'a b c d'(ax^3 + bx^2 + cx + d)" << std::endl;
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;
    SolveEquation(a, b, c, d);

    std::cout << std::endl;
}

int main() {
    std::cout << "This is a code that solves equations up to the 3rd degree" << std::endl;
    for (;;) {
        Program();
    }
    return 0;
}
