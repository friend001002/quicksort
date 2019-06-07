#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Quick_sort
{
  public:

  Quick_sort(vector<T>& in) 
    : data_(in)
  {
    
  }

  virtual ~Quick_sort()
  {
    data_.clear();
    data_.shrink_to_fit();
  }

  bool Sort(vector<T>& out)
  {
    if (0 == data_.size())
    {
      cerr << "No data to sort!\n";

      return false;
    }

    this->Do_sort(0, data_.size() - 1);

    out = data_;

    return true;
  }

  private:

  vector<T> data_;

  void Do_sort(size_t low_index, size_t high_index)
  {
    if (low_index < high_index)
    {
      size_t part_index = this->Partition(low_index, high_index);

      this->Do_sort(low_index,      part_index - 1);  // Before part_index
      this->Do_sort(part_index + 1, high_index); // After part_index
    }
  }

  void Swap(size_t a, size_t b)
  {
    T tmp = data_.at(a);
    data_.at(a) = data_.at(b);
    data_.at(b) = tmp;
  }

  size_t Partition(size_t low_index, size_t high_index)
  {
    T pivot = data_.at(high_index);

    int64_t smaller_el_index { low_index - 1 };

    for (size_t j { low_index }; j <= high_index - 1; ++j)
    {
      if (data_.at(j) <= pivot)
      {
        ++smaller_el_index;
        Swap(smaller_el_index, j);
      }
    }

    Swap(smaller_el_index + 1, high_index);

    return smaller_el_index + 1;
  }
};

int main()
{
  vector<int> v { 10, 80, 30, 90, 40, 50, 70 };
  //vector<int> v { 10, 7, 8, 9, 1, 5 };

  Quick_sort<int> qs(v);

  vector<int> res;

  bool succ = qs.Sort(res);

  if (succ)
  {
    for (int i : res)
    {
      cout << i << ' ';
    }

    cout << endl;
  }
  else
  {
    cerr << "Error\n";
  }

  cin.get();

  return 0;
}
