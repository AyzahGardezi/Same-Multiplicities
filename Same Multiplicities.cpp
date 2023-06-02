#include <vector>

class Same {
public :
    static bool comp(std::vector<int>&a, std::vector<int>&b) {
      if (a.size()!=b.size())
        return false;
      int size = a.size();
      
      for(int i = 0; i < size; i++)
        {
        if(a[i]<0)
          a[i]*=-1;
      }
      
      //insertion sort applied to a
      for(int i = 1; i < size; i++)
        {
          if(a[i] < a[i-1])
          {
            int key = a[i], hole = i;
            int j = i-1;
            while (j >= 0 && key < a[j])
              {
              a[j+1] = a[j];
              hole = j;
              j--;
            }
            a[hole] = key;
          }
        }
      
      //insertion sort applied to b
      for(int i = 1; i < size; i++)
        {
          if(b[i] < b[i-1])
          {
            int key = b[i], hole = i;
            int j = i-1;
            while (j >= 0 && key < b[j])
              {
              b[j+1] = b[j];
              hole = j;
              j--;
            }
            b[hole] = key;
          }
        }
      
      for(int i = 0; i < size; i++)
        {
        if (a[i]*a[i] != b[i])
          return false;
      }
      return true;
    }
};
