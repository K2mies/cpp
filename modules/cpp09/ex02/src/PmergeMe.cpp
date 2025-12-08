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
#include "ansi_colors.hpp"

// --------------------------------------------------------- getters and setters

const std::vector<int> &PmergeMe::getVector(){ return( _vec ); }
const std::deque<int> &PmergeMe::getDeque(){ return( _deq ); }

size_t  PmergeMe::getVecSize(){ return( _vec.size() ); }
size_t  PmergeMe::getDeqSize(){ return( _deq.size() ); }

// --------------------------------------------------------------------- parsing

/*
 * @brief main funcion to run program
 */
bool PmergeMe::run(int argc, char **argv) {
  if (!parse(argc, argv)) {
    return (false);
  }
  sortVec(1);

  #ifdef DEBUG
  std::cout << "final output: ";
  print_container(_vec);
  #endif

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

  #ifdef DEBUG
  std::cout << "Vector before swap: \n";
  print_container(_vec);
  #endif

  if (!parse_numbers(_deq, argc, argv)) {
    return (false);
  }

  #ifdef DEBUG
  std::cout << "Deque before swap: \n";
  print_container(_deq);
  #endif

  return (true);
}

// ------------------------------------------------------------- vector
/*
 * @brief merge insertion for vector using the jacobsath sequence
 */
void PmergeMe::sortVec(size_t scale) {
  size_t size = _vec.size();
  size_t unitSize = size / scale;
  static int recursion_level = 0;

  if (unitSize < 2)
    return;

  recursion_level++;

  #ifdef DEBUG
  std::cout << "recursion level: " << recursion_level << std::endl;
  std::cout << "scale: " << scale << std::endl;
  #endif

  // Comparing the pairs to each other
  for (size_t i = 0; i + (scale * 2) <= size; i += (scale * 2)) {
    int a1 = _vec[i + scale - 1];
    int b1 = _vec[i + (scale * 2) - 1];

    // if b1 is smaller than a1, we swap pairs
    if (b1 < a1) {
      for (size_t j = 0; j < scale; j++)
        std::swap(_vec[i + j], _vec[i + scale + j]);
    }
  }

  #ifdef DEBUG
  print_container(_vec);
  std::cout << std::endl;
  #endif

  sortVec(scale * 2);
  insertVec(scale);
}

void PmergeMe::insertVec(size_t scale)
{
  size_t size = _vec.size();

  std::vector<int> main;
  std::vector<int> pend;

  main.reserve(size);
  pend.reserve(size);

  // Inserting b1 to the main
  main.insert(main.end(), _vec.begin(), _vec.begin() + scale);
  // Inserting a1 to the main
  main.insert(main.end(), _vec.begin() + scale, _vec.begin() + (scale * 2));

  #ifdef DEBUG
  std::cout << "b1 and a1 main insertion: ";
  print_container(main);
  #endif

  //inserting all the rest of the a's to main
  for (size_t i = (scale * 3); i + scale <= size; i += (scale * 2))
  {
       for (size_t j = 0; j < scale; j++)
            main.push_back(_vec[j + i]);
  }

  //inserting all the rest of the b's to main
  for (size_t k = (scale * 2); k + scale <= size; k += (scale * 2))
  {
       for (size_t j = 0; j < scale; j++)
      {
            pend.push_back(_vec[j + k]);
      }
  }

  size_t mainElements = main.size();
  size_t pendElements = pend.size();

  // checking if there are any leftovers that could not be formed into pairs
  std::vector<size_t> leftOvers = checkForLeftOvers<std::vector<size_t>>(_vec, mainElements, pendElements);

  if(pendElements != 0)
  {
    size_t pendBlockSize = pendElements / scale;
    std::vector<size_t> jacobOrder = findJacobsthalOrder<std::vector<size_t>>(pendBlockSize);

    std::vector<int> temp;
    size_t blockSize = scale;

    for(size_t index : jacobOrder)
    {
      size_t start = (index - 1) * blockSize;
      if(start >= pendElements)
        continue;

      size_t end = start + blockSize;
      if(end > pendElements)
        end = pendElements;

      size_t mainIndex = binarySearch(main, pend[end - 1], blockSize);
      main.insert(main.begin() + mainIndex, pend.begin() + start, pend.begin() + end);
    }
  }
  if(leftOvers.size() != 0)
    main.insert(main.end(), leftOvers.begin(), leftOvers.end());
  _vec = main;

  static int recursion_level = 0;
  recursion_level++;

  #ifdef DEBUG
  std::cout << "insert recursion level: " << recursion_level << std::endl;
  std::cout << "insert scale: " << scale << std::endl;

  std::cout<< "source: ";
  print_container(_vec);
  std::cout << "main: ";
  print_container(main);
  std::cout << "pend: ";
  print_container(pend);
  std::cout << "left over: ";
  print_container(leftOvers);
  std::cout << std::endl;
  #endif
}

// ---------------------------------------------------------------- deq
/*
 * @brief merge insertion for vector using the jacobsath sequence
 */
void PmergeMe::sortDeq(size_t scale) {
  size_t size = _deq.size();
  size_t unitSize = size / scale;
  static int recursion_level = 0;

  if (unitSize < 2)
    return;

  recursion_level++;

  #ifdef DEBUG
  std::cout << "recursion level: " << recursion_level << std::endl;
  std::cout << "scale: " << scale << std::endl;
  #endif

  // Comparing the pairs to each other
  for (size_t i = 0; i + (scale * 2) <= size; i += (scale * 2)) {
    int a1 = _deq[i + scale - 1];
    int b1 = _deq[i + (scale * 2) - 1];

    // if b1 is smaller than a1, we swap pairs
    if (b1 < a1) {
      for (size_t j = 0; j < scale; j++)
        std::swap(_deq[i + j], _deq[i + scale + j]);
    }
  }

  #ifdef DEBUG
  print_container(_vec);
  std::cout << std::endl;
  #endif

  sortDeq(scale * 2);
  insertDeq(scale);
}

void PmergeMe::insertDeq(size_t scale)
{
  size_t size = _deq.size();

  std::deque<int> main;
  std::deque<int> pend;

 // main.reserve(size);
 // pend.reserve(size);

  // Inserting b1 to the main
  main.insert(main.end(), _deq.begin(), _deq.begin() + scale);
  // Inserting a1 to the main
  main.insert(main.end(), _deq.begin() + scale, _deq.begin() + (scale * 2));

  #ifdef DEBUG
  std::cout << "b1 and a1 main insertion: ";
  print_container(main);
  #endif

  //inserting all the rest of the a's to main
  for (size_t i = (scale * 3); i + scale <= size; i += (scale * 2))
  {
       for (size_t j = 0; j < scale; j++)
            main.push_back(_deq[j + i]);
  }

  //inserting all the rest of the b's to main
  for (size_t k = (scale * 2); k + scale <= size; k += (scale * 2))
  {
       for (size_t j = 0; j < scale; j++)
      {
            pend.push_back(_deq[j + k]);
      }
  }

  size_t mainElements = main.size();
  size_t pendElements = pend.size();

  // checking if there are any leftovers that could not be formed into pairs
  std::deque<size_t> leftOvers = checkForLeftOvers<std::deque<size_t>>(_deq, mainElements, pendElements);

  if(pendElements != 0)
  {
    size_t pendBlockSize = pendElements / scale;
    std::deque<size_t> jacobOrder = findJacobsthalOrder<std::deque<size_t>>(pendBlockSize);

    std::deque<int> temp;
    size_t blockSize = scale;

    for(size_t index : jacobOrder)
    {
      size_t start = (index - 1) * blockSize;
      if(start >= pendElements)
        continue;

      size_t end = start + blockSize;
      if(end > pendElements)
        end = pendElements;

      size_t mainIndex = binarySearch(main, pend[end - 1], blockSize);
      main.insert(main.begin() + mainIndex, pend.begin() + start, pend.begin() + end);
    }
  }
  if(leftOvers.size() != 0)
    main.insert(main.end(), leftOvers.begin(), leftOvers.end());
  _deq = main;

  static int recursion_level = 0;
  recursion_level++;

  #ifdef DEBUG
  std::cout << "insert recursion level: " << recursion_level << std::endl;
  std::cout << "insert scale: " << scale << std::endl;

  std::cout<< "source: ";
  print_container(_deq);
  std::cout << "main: ";
  print_container(main);
  std::cout << "pend: ";
  print_container(pend);
  std::cout << "left over: ";
  print_container(leftOvers);
  std::cout << std::endl;
  #endif
}
