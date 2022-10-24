#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

/**
 * Start from the side with lower height and move to the other side to find the smallest rain-trapped container each time.
 * until all elements in vector have been checked.
 */
class Solution {
public:
  int trap(vector<int>& height) {
    int result = 0;

    uint32_t start_index = 0;
    uint32_t ending_index = height.size() - 1;

    int start_init_index = 0;
    int ending_init_index = ending_index;
    while (start_index < ending_index) {
      if (height.at(start_index) > height.at(ending_index)) {
        ending_init_index = ending_index;
        while(start_index < ending_index) {
          if (height.at(ending_init_index) < height.at(ending_index)) {
            result += get_trapped_rain(height, ending_index, ending_init_index);
            ending_init_index = ending_index;
            break;
          }
          ending_index--;
        }
      } else {
        start_init_index = start_index;
        while(start_index < ending_index) {
          if (height.at(start_init_index) < height.at(start_index)) {
            result += get_trapped_rain(height, start_init_index, start_index);
            start_init_index = start_index;
            break;
          }
          start_index++;
        }
      }
    }

    result += get_trapped_rain(height, start_init_index, ending_init_index);

    return result;
  }

  int get_trapped_rain(vector<int>& height, int left_index, int right_index) {
    int amount_of_trapped_rain = 0;

    int lower_wood_heihgt = min(height.at(left_index), height.at(right_index));

    left_index = left_index + 1;

    while (left_index < right_index) {
      amount_of_trapped_rain += lower_wood_heihgt - height.at(left_index);
      left_index++;
    }

    return amount_of_trapped_rain;
  }

    
};