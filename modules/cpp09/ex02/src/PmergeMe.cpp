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
  sortVec(parsed_vec_, 1);
  // recursivelySwapVec(parsed_vec_, 1);
  //	std::cout << "Vector after swaps\n"
  //	print_container(parsed_vec_);

  return (true);
}

/*
 * @brief main parsing function to add argv sequence to a container
 */
bool PmergeMe::parse(int argc, char **argv) {
  if (!parse_numbers(parsed_vec_, argc, argv)) {
    std::cerr << "Error: vector parsing failed" << std::endl;
    return (false);
  }
  std::cout << "Vector before swap: \n";
  print_container(parsed_vec_);
  if (!parse_numbers(parsed_deq_, argc, argv)) {
    return (false);
  }
  std::cout << "Deque before swap: \n";
  print_container(parsed_deq_);
  return (true);
}

void PmergeMe::sortVec(std::vector<int> &vec, size_t scale) {
  size_t size = vec.size();
  size_t unitSize = size / scale;

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
  std::cout << "size: " << scale << std::endl;
  for (const auto &s : vec)
    std::cout << s << " ";
  std::cout << std::endl;
  sortVec(vec, scale * 2);
}

// ------------------------------------------------------------- vector
// recursion
// void PmergeMe::recursivelySwapVec(std::vector<int> &vec, size_t scale) {
//  std::cout << "size: " << scale << std::endl;
//  if (scale > vec.size() / 2)
//    return;
//  for (size_t i = 0; i + (scale * 2) <= vec.size(); i += (scale * 2)) {
//    int leftEnd = vec[i + scale - 1];
//    int rightEnd = vec[i + scale + scale - 1];
//    if (leftEnd > rightEnd) {
//      for (size_t j = 0; j < scale; j++) {
//        std::swap(vec[i + j], vec[i + scale + j]);
//      }
//    }
//    // i += scale;
//  }
//  for (const auto &s : vec)
//    std::cout << s << " ";
//  std::cout << std::endl;
//  recursivelySwapVec(vec, scale * 2);
//}
