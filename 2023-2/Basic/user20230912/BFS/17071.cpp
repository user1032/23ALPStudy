#include <iostream>
#include <cmath>

int find_2pow(int a);

bool find_n(int a, int b, int j);

int find_1st(int a, int b);

int solution = -1;

int upper = 50;

bool state_all = 0;

int up2 = 0;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int input1, input2;

    std::cin >> input1 >> input2;

    for (int i = 0, j = 0; input2 <= 500000; i++, j++) {

        input2 += j;
        if (input2 > 500000)
            continue;
        if (find_n(input1, input2, i)) {
            solution = j;
            break;
        }
    }

    std::cout << solution;

    return 0;
}

int find_2pow(int a) {

    if (a < 2)
        return 0;

    int count = 0;
    double temp = a;

    count = (int)log2(temp);

    if (pow(2, count) * 1.5 <= a) {
        if (upper <= count) {
            return upper;
        }
        return (count + 1);
    }
    else {
        while (upper <= count) {
            return upper;
        }
        return count;
    }

    return 0;

}

bool find_n(int a, int b, int j) {

    int dumy, temp, tc = 0, d2;
    up2 = a;
    state_all = 0;

    if (a >= b) {
        if (j >= a - b && ((j - (a - b)) % 2) == 0)
            return 1;
        else
            return 0;//?
    }
    if (a == 0) {
        a = 1;
        tc++;
    }

    temp = find_1st(a, b);

    j = j - temp;
    dumy = b - a * pow(2, temp);

    while (dumy != 0) {

        if ((j - tc) >= dumy) {

            if (dumy < 0) {
                dumy *= -1;
                if ((j - tc) < dumy) {
                    dumy *= -1;
                    goto label2;
                }
                if (dumy < 0)
                    dumy *= -1;
            }
            if (state_all == 0 && (j - tc - dumy) % 2 == 0)
                return 1;
            if (state_all == 1)
                return 1;

        }label2:

        if (dumy < 0) {
            dumy *= -1;
            if (find_2pow(dumy) == upper && dumy / pow(2, upper) > 2) {
                tc += dumy / pow(2, upper);
                dumy = dumy % int(pow(2, upper));
            }

            d2 = pow(2, find_2pow(dumy));
            if (d2 != 1)
                state_all = 1;

            dumy = dumy - d2;
            dumy *= -1;
            tc++;
        }
        else {
            if (find_2pow(dumy) == upper && dumy / pow(2, upper) > 2) {
                tc += int(dumy / pow(2, upper));
                dumy = dumy % int(pow(2, upper));
            }

            d2 = pow(2, find_2pow(dumy));
            if (d2 != 1)
                state_all = 1;

            dumy = dumy - d2;
            tc++;
        }
    }

    if (j >= tc && state_all == 1)
        return 1;
    else if (j >= tc && state_all == 0 && (j - tc) % 2 == 0)
        return 1;
    else return 0;

}

int find_1st(int a, int b) {

    int count = 0;
    if (a == 0)
        a = 1;
    double temp = double(b) / double(a);

    count = (int)log2(temp);

    upper = count;

    if (pow(2, count) * a * 1.5 <= b) {
        upper++;
        return (count + 1);
    }
    else return count;

}

