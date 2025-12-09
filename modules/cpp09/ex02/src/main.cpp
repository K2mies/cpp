/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:22:48 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/27 13:55:54 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Usage: ./PmergeMe <list of positive integers\n>";
    return (1);
  }
  PmergeMe pmerge;
  try
  {
    if (!pmerge.parse( argc, argv ))
    {
      return (1);
    }
    std::cout << "Before: ";
    print_container( pmerge.getVector() );
    auto timeStartVec = std::chrono::high_resolution_clock::now();
    pmerge.sortVec(1);
    auto timeStopVec = std::chrono::high_resolution_clock::now();
    std::cout << "After: ";
    print_container( pmerge.getVector() );
    auto durationVec = std::chrono::duration_cast<std::chrono::microseconds>(timeStopVec - timeStartVec);
    if (std::is_sorted(pmerge.getVector().begin(), pmerge.getVector().end()))
    {
      std::cout 
        << "Time to process a range of " << pmerge.getVecSize()
        << " elements with std::vector: " << durationVec.count()
        << " μs\n";
    }
    else
    {
      std::cerr << "Error: Container not sorted" << std::endl;
      return (2);
    }

    //std::cout << "Before: ";
    //print_container( pmerge.getDeque() );
    auto timeStartDeq = std::chrono::high_resolution_clock::now();
    pmerge.sortDeq(1);
    auto timeStopDeq = std::chrono::high_resolution_clock::now();
    //std::cout << "After: ";
    //print_container( pmerge.getDeque() );
    auto durationDeq = std::chrono::duration_cast<std::chrono::microseconds>(timeStopDeq - timeStartDeq);
    if (std::is_sorted(pmerge.getDeque().begin(), pmerge.getDeque().end()))
    {
      std::cout 
        << "Time to process a range of " << pmerge.getDeqSize()
        << " elements with std::deque: " << durationDeq.count()
        << " μs\n";
    }
    else
    {
      std::cerr << "Error: Container not sorted" << std::endl;
      return (2);
    }
  }
  catch(const std::string &e)
  {
    std::cerr << "Error: " << e << std::endl;
  }
  //pmerge.run(argc, argv);
  return (0);
}
