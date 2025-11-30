/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:14:12 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/27 13:55:55 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PmergeMe.hpp"

// --------------------------------------------------------------------- parsing
/*
 * @brief main funcion to run program
 */

bool PmergeMe::run(int argc, char **argv) {
  if (!parse(argc, argv)) {
    return (false);
  }
  sortVec(_vec, 1);
  // recursivelySwapVec(_vec, 1);
  //	std::cout << "Vector after swaps\n"
  //	print_container(_vec);

  return (true);
}

/*
 * @brief main parsing function to add argv sequence to a container
 */
bool PmergeMe::parse(int argc, char **argv) {
  if (!parse_numbers(_vec, argc, argv)) {
    std::cerr << "Error: vector parsing failed" << std::endl;
    return (false);
  }
  std::cout << "Vector before swap: \n";
  print_container(_vec);
  if (!parse_numbers(_deq, argc, argv)) {
    return (false);
  }
  std::cout << "Deque before swap: \n";
  print_container(_deq);
  return (true);
}

// ------------------------------------------------------------- vector
void PmergeMe::sortVec(std::vector<int> &vec, size_t scale) {
  size_t size = vec.size();
  size_t unitSize = size / scale;
  static int recursion_level = 0;

  recursion_level++;
  std::cout << "recursion level: " << recursion_level << std::endl;

  if (unitSize < 2)
    return;

  // Comparing the pairs to each other
  for (size_t i = 0; i + (scale * 2) <= size; i += (scale * 2)) {
    int a1 = vec[i + scale - 1];
    int b1 = vec[i + (scale * 2) - 1];

    // if b1 is smaller than a1, we swap pairs
    if (b1 < a1) {
      for (size_t j = 0; j < scale; j++)
        std::swap(vec[i + j], vec[i + scale + j]);
    }
  }
  // for debugging
  for (const auto &s : vec)
    std::cout << s << " ";
  std::cout << std::endl;
  sortVec(vec, scale * 2);
}
