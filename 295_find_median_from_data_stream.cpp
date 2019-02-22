/*Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?*/
class MedianFinder {
  priority_queue<double> firstHalf; //maxheap to store first half of the elements
  priority_queue<double, vector<double>, greater<double>> secondHalf; // min heap to store second half of the elements
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
      //check if the number belongs to first or second half
      if (firstHalf.empty() || firstHalf.top() > num) {
        //cout<<"Inserting in first half::"<<num<<"\n";
        firstHalf.push(num);
      } else {
        //cout<<"Inserting in second half::"<<num<<"\n";
        secondHalf.push(num);
      }

      //now the number of elements in each half cannot exceed by 1
      if (firstHalf.size() > secondHalf.size() + 1) {
        secondHalf.push(firstHalf.top());
        firstHalf.pop();
      }
      if (secondHalf.size() > firstHalf.size() + 1) {
        firstHalf.push(secondHalf.top());
        secondHalf.pop();
      }

    }

    double findMedian() {
      //we have even total numbers
      if (firstHalf.size() == secondHalf.size()) {
        return (firstHalf.top() + secondHalf.top())/2;
      }
      //we have odd total numbers
      return firstHalf.size() > secondHalf.size() ? firstHalf.top() : secondHalf.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
