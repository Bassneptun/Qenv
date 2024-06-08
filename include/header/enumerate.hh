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

    Iterator& operator++();
    bool operator!=(const Iterator& other) const;
    std::pair<size_t, value_type&> operator*() const;

   private:
    it_type it;
    size_t index;
  };

  Enumerate(Container& container) : container(container) {}

  Iterator begin() const;

  Iterator end() const;

 private:
  Container& container;
};

#endif
