/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:53:49 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/20 13:09:51 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ansi_colors.hpp"
#include <deque>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

class PmergeMe {
private:
  std::vector<int> _vec;
  std::deque<int> _deq;

public:
  PmergeMe() = default;
  PmergeMe(PmergeMe const &);
  ~PmergeMe() = default;

  PmergeMe &operator=(PmergeMe const &);

  bool parse(int argc, char **argv);
  bool run(int argc, char **argv);
  void sortVec(size_t scale);
  void insertVec(size_t scale);
};

/* --------------------------- template functions ----------------------------*/

// --------------------------------------------------------------------- parsing

/*
 * @brief helper function to check fo doubles
 */
template <typename T> bool check_for_doubles(T const &container) {
  for (size_t i = 0; i < container.size(); i++) {
    for (size_t j = i + 1; j < container.size(); j++) {
      if (container[j] == container[i])
        return (true);
    }
  }
  return (false);
}

/*
 * @brief main parsing function to add argv sequence to a container
 */
template <typename T>
static bool parse_numbers(T &container, int argc, char **argv) {
  std::regex reg_a(
      R"(^[-+]?(\d+\.\d*)[f]?$)"); // checks for valid floating point
  std::regex reg_b(
      R"(\d+([^\d\s])\d+)"); // checks for invalid symbol between two numbers

  for (int i = 1; i < argc; i++) {
    if (std::regex_match(argv[i], reg_a)) {
      std::cerr << "Error: numbers must be positive integers only (floating "
                   "point numbers not allowed)"
                << std::endl;
      return (false);
    }
    if (std::regex_match(argv[i], reg_b)) {
      std::cerr << "Error: invalid symbols" << std::endl;
      return (false);
    }
    try {
      container.push_back(std::stoi(argv[i]));
    } catch (std::exception const &e) {
      std::cerr << "Error: invalid number" << std::endl;
      return (false);
    }
    if (std::stoi(argv[i]) < 0) {
      std::cerr << "Error: only positive intigers allowed" << std::endl;
      return (false);
    }
  }
  if (check_for_doubles(container)) {
    std::cerr << "Error: no duplicates allowed" << std::endl;
    return (false);
  }
  return (true);
}

// ----------------------------------------------------------------------- print
template <typename T> void print_container(T const &container) {
  for (size_t i = 0; i < container.size(); i++) {
    std::cout << "(" << container[i] << "), ";
  }
  std::cout << std::endl;
}

// ------------------------------------------------------------------- insertion
template<typename Container, typename ContainerType>
Container checkForLeftOvers(ContainerType &source,
                                  size_t mainSize,
                                  size_t pendSize)
{
  Container leftOvers;
  size_t  size = source.size();
  size_t remainingElements = size - mainSize - pendSize;

  // If there were leftovers, we add them into the lefovers vector
  if (remainingElements > 0)
  {
    size_t leftOverStart = size - remainingElements;
    for(size_t i = leftOverStart; i < size; i++)
      leftOvers.push_back(source[i]);
  }
  return(leftOvers);
}

template<typename Container>
size_t binarySearch(Container &main, int num, size_t blockSize)
{
  int midBlock;
  int mid;
  int numOfBlocks = main.size() / blockSize;
  int low = 1;
  int high = numOfBlocks;

  while(low <= high)
  {
    midBlock = low + (high - low) / 2;
    mid = (midBlock * blockSize) - 1;

    if(main[mid] == num)
      return(mid);
    if(main[mid] < num)
      low = midBlock + 1;
    else
      high = midBlock - 1;
  }
  if(main[mid] < num)
    return(mid + 1);
  return(mid - blockSize + 1);
}

// ------------------------------------------------------------------ Jacobsthal
template<typename Container>
Container findJacobsthalOrder(size_t pendsize)
{
  Container jacobOrder;
  if (pendsize == 0)
    return (jacobOrder);

  size_t j0 = 0; // Jacob -2 (j(0))
  size_t j1 = 1; // Jacob -1 (j(1))
  size_t prevJacob = 0;

  while(prevJacob < pendsize)
  {
    size_t currJacob = j1;

    if (currJacob == 1)
    {
      size_t nextJacob = j1 + (2 * j0);
      j0 = j1;
      j1 = nextJacob;
      continue;
    }
    size_t topJacob = currJacob;
    if (currJacob > pendsize)
      topJacob = pendsize;
    for(size_t i = topJacob; i > prevJacob; i--)
      jacobOrder.push_back(i);
    prevJacob = currJacob;
    size_t nextJacob = j1 + (2 * j0);
    j0 = j1;
    j1 = nextJacob;
  }
  return(jacobOrder);
}
