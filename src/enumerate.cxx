#include "../include/header/enumerate.hh"

template <typename Container>
typename Enumerate<Container>::Iterator&
Enumerate<Container>::Iterator::operator++() {
  ++it;
  ++index;
  return *this;
}

template <typename Container>
bool Enumerate<Container>::Iterator::operator!=(const Iterator& other) const {
  return it != other.it;
}

template <typename Container>
std::pair<size_t, typename Container::value_type&>
Enumerate<Container>::Iterator::operator*() const {
  return {index, *it};
}

template <typename Container>
typename Enumerate<Container>::Iterator Enumerate<Container>::begin() const {
  return Iterator(container.begin(), 0);
}

template <typename Container>
typename Enumerate<Container>::Iterator Enumerate<Container>::end() const {
  return Iterator(container.end(), container.size());
}
