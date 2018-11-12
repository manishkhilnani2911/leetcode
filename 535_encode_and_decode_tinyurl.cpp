/*Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.*/
class Solution {
  //Am_Go_Mi_Ub_Ba_Ad_Li_Ali_Sa_Fa
  unordered_map<int,string> m;
  int id = 0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
      m[id] = longUrl;
      return "http://tinyurl.com/" + to_string(id++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
      //find the last number
      int pos = shortUrl.find_last_of("/");
      string num = shortUrl.substr(pos+1);
      return m[stoi(num)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
