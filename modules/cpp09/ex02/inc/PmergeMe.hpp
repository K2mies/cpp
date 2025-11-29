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

#include <deque>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

class PmergeMe {
private:
  std::vector<int> parsed_vec_;
  std::deque<int> parsed_deq_;

public:
  PmergeMe() = default;
  PmergeMe(PmergeMe const &);
  ~PmergeMe() = default;

  PmergeMe &operator=(PmergeMe const &);
  // ---------------------------------------------------------------------
  // parsing
  bool parse(int argc, char **argv);
  bool run(int argc, char **argv);
  // void recursivelySwapVec(std::vector<int> &vec, size_t scale);
  void sortVec(std::vector<int> &vec, size_t scale);
};

// ---------------------------------------------------------- template functions
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
    std::cout << container[i] << std::endl;
  }
}
