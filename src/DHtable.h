#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <cmath>


class DHtable {
public:

    DHtable(int joints) {
        numJoints = joints;
        DHParem.resize(numJoints);
    }

    //setters
    void setTheta(std::vector<double> theta) {
        for (int i = 0; i < theta.size(); i++) {
            DHParem[i][0] = theta[i];
        }
    } 

    void setAlen(std::vector<double> alen) {
        for (int i = 0; i < alen.size(); i++) {
            DHParem[i][1] = alen[i];
        }
    } 

    void setDlen(std::vector<double> dlen) {
        for (int i = 0; i < dlen.size(); i++) {
            DHParem[i][2] = dlen[i];
        }
    }

    void setAlpha(std::vector<double> alpha) {
        for (int i = 0; i < alpha.size(); i++) {
            DHParem[i][3] = alpha[i];
        }
    }
    
    std::array<std::array<double, 4>, 4> setTMat(std::array<double, 4> jntParam) {
        std::array<std::array<double, 4>, 4> TMat{};
        TMat[0][0] = cos(jntParam[0]); TMat[0][1] = -sin(jntParam[0]) * cos(jntParam[3]); TMat[0][2] = sin(jntParam[0]) * sin(jntParam[3]); TMat[0][3] = jntParam[1] * cos(jntParam[0]);
        TMat[1][0] = sin(jntParam[0]); TMat[1][1] = cos(jntParam[0]) * cos(jntParam[3]); TMat[1][2] = -cos(jntParam[0]) * sin(jntParam[3]); TMat[1][3] = jntParam[1] * sin(jntParam[0]);
        TMat[2][0] = 0; TMat[2][1] = sin(jntParam[3]); TMat[2][2] = cos(jntParam[3]); TMat[2][3] = jntParam[2];
        TMat[3][0] = 0; TMat[3][1] = 0; TMat[3][2] = 0; TMat[3][3] = 1; 

        return TMat;
    }

    std::array<std::array<double, 4>, 4> matMul(std::array<std::array<double, 4>, 4> A, std::array<std::array<double, 4>, 4> B) {
        std::array<std::array<double, 4>, 4> C{};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }

    void setFinalMat() {
        finalMat = {};
        for (int i = 0; i < 4; i++) {
            finalMat[i][i] = 1;
        }

        for (int i = 0; i < numJoints; i++) {
            finalMat = matMul(finalMat, setTMat(DHParem[i]));
        }
    }

    //getters
    std::array<std::array<double, 4>, 4> getFinalMat() {
        return finalMat;
    }


    //print 
    void printTable() {
        std::cout << "theta" << " | " << "a" << " | " << "d" << " | " << "alpha" << std::endl;
        for (auto i : DHParem) {
            std::cout << i[0] << " | " << i[1] << " | " << i[2] << " | " << i[3] << std::endl;
        }
    }

    void printFinalMat() {
        for (auto i : finalMat) {
            std::cout << i[0] << " | " << i[1] << " | " << i[2] << " | " << i[3] << std::endl;
        }
    }

private:
    int numJoints; 
    std::vector<std::array<double, 4>> DHParem;
    std::array<std::array<double, 4>, 4> finalMat{};

};