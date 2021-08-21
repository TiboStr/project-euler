#include <iostream>
#include <string>
using namespace std;

/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

int len(string dict[], int num);

int main() {
    string words[91];

    words[1] = "one";
    words[2] = "two";
    words[3] = "three";
    words[4] = "four";
    words[5] = "five";
    words[6] = "six";
    words[7] = "seven";
    words[8] = "eight";
    words[9] = "nine";
    words[10] = "ten";
    words[11] = "eleven";
    words[12] = "twelve";
    words[13] = "thirteen";
    words[14] = "fourteen";
    words[15] = "fifteen";
    words[16] = "sixteen";
    words[17] = "seventeen";
    words[18] = "eighteen";
    words[19] = "nineteen";
    words[20] = "twenty";
    words[30] = "thirty";
    words[40] = "forty";
    words[50] = "fifty";
    words[60] = "sixty";
    words[70] = "seventy";
    words[80] = "eighty";
    words[90] = "ninety";

    long sum = 0;
    for (int i = 1; i < 1000; i++) {
       sum += len(words, i);
    }
    sum += string("onethousand").size();

    cout << "There are " << sum << " letters used if we write all the numbers from 1 to 1000 out in words" << endl;
}

int len(string dict[], int num) {
    if (num < 21) {
        return dict[num].size();

    } else if (num < 100) {
        return dict[num/10*10].size() + len(dict, num%10);

    } else if (num < 1000) {
        string append = num % 10 == 0 && num % 100 == 0 ? "hundred" : "hundredand";
        return (dict[stoi(to_string(num).substr(0,1))] + append).size() + len(dict, num%100);
    }
    
    return 0;
}