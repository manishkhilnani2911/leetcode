/*Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Example 1:

Input: 123
Output: "One Hundred Twenty Three"
Example 2:

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Example 4:

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"*/
class Solution {
  //FA_Mi_Ye_Am_Go_Bl_Li_Pa_Sap_Ub_IBM_Sn_Ya_Ad_Air
public:
    string numberToWords(int num) {
      if (!num) {
        return "Zero";
      }
      int billion = num/1000000000;
      int million = (num - (billion*1000000000))/1000000;
      int thousand = (num - (billion*1000000000) - (million*1000000))/1000;
      int hundred = (num - (billion*1000000000) - (million*1000000) - (thousand*1000));
      string billion_str = "", million_str = "", thousand_str = "", hundred_str = "";
      if (billion) {
        billion_str = getHundred(billion) + " " + "Billion";
      }
      if (million) {
        million_str = getHundred(million) + " " + "Million";
      }
      if (thousand) {
        thousand_str = getHundred(thousand) + " " + "Thousand";
      }
      if (hundred) {
        hundred_str = getHundred(hundred);
        cout<<hundred_str;
      }
      string res = "";
      if (billion_str.size() > 0) {
        res += billion_str;
        if (million_str.size() > 0) {
          res += " " + million_str;
        }
        if (thousand_str.size() > 0) {
          res += " " + thousand_str;
        }
        if (hundred_str.size() > 0) {
          res += " " + hundred_str;
        }
      } else if (million_str.size() > 0) {
        res += million_str;
        if (thousand_str.size() > 0) {
          res += " " + thousand_str;
        }
        if (hundred_str.size() > 0) {
          res += " " + hundred_str;
        }
      } else if (thousand_str.size() > 0) {
        res += thousand_str ;
        if (hundred_str.size() > 0) {
          res += " " + hundred_str;
        }
      } else if (hundred_str.size() > 0) {
        res = hundred_str;
      }
      return res;
    }

    //api to print string for 3 digit number
    string getHundred(int num) {
      if (!num) {
        return "";
      }
      int hundred = num/100;
      string res;
      if (hundred) {
        res = ones(hundred) + " " + "Hundred";
        if (num-hundred*100) {
          res += " " + getTen(num - hundred*100);
        }
      } else {
        //cout<<getTen(num)<<"\n";
        res = getTen(num);
      }
      return res;
    }

    string getTen(int num) {
      //cout<<"ten::"<<num<<"\n";
      if (num < 20 && num > 9) {
        return lessThanTwenty(num);
      }
      string res;
      int ten = num/10;
      if (ten) {
        res += tens(ten);
        if (num - ten*10) {
          res += " " + ones(num-ten*10);
        }
      } else {
        res += ones(num);
      }
      return res;
    }

    string lessThanTwenty(int num) {
      switch (num) {
        case 10: return "Ten";
        case 11 : return "Eleven";
        case 12: return "Twelve";
        case 13: return "Thirteen";
        case 14: return "Fourteen";
        case 15: return "Fifteen";
        case 16: return "Sixteen";
        case 17: return "Seventeen";
        case 18: return "Eighteen";
        case 19: return "Nineteen";
          case 20: return "Twenty";
      }
      return "";
    }

    string tens(int num) {
      switch(num) {
        case 2: return "Twenty";
        case 3: return "Thirty";
        case 4: return "Forty";
        case 5: return "Fifty";
        case 6: return "Sixty";
        case 7: return "Seventy";
        case 8: return "Eighty";
        case 9: return "Ninety";
      }
      return "";
    }

    string ones(int num) {
      switch(num) {
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
      }
      return "";
    }
};
