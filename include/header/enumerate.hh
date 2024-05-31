#ifndef ENUMERATE_HH
#define ENUMERATE_HH

#include <iterator>

template <typename Container>
class Enumerate {
 public:
  class Iterator {
   public:
    using value_type = typename Container::value_type;
    using it_type = typename Container::iterator;

    Iterator(it_type it, size_t index) : it(it), index(index) {}

    Iterator& operator++() {
      ++it;
      ++index;
      return *this;
    }
    bool operator!=(const Iterator& other) const { return it != other.it; }
    std::pair<size_t, value_type&> operator*() const { return {index, *it}; }

   private:
    it_type it;
    size_t index;
  };

  Enumerate(Container& container) : container(container) {}

  Iterator begin() const { return Iterator(container.begin(), 0); }

  Iterator end() const { return Iterator(container.end(), container.size()); }

 private:
  Container& container;
};

#endif
