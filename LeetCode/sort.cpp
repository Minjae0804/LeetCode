#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstddef>
#include <random>

// 무작위 정수 벡터 생성
std::vector<int> generateRandomVector(size_t size) {
	std::vector<int> vec(size);
	std::mt19937 gen(42);
	std::uniform_int_distribution<int> dis(1, 1000000);
	for (size_t i = 0; i < size; ++i) vec[i] = dis(gen);
	
	return vec;
}

// 힙에 할당된 객체들의 총 크기
size_t totalAllocated = 0;

// 힙에 할당한 객체의 크기를 totalAllocated에 합함
void* operator new(size_t size) {
	totalAllocated += size;
	return malloc(size);
}

void operator delete(void* memory, size_t size) noexcept { free(memory); }

// 재귀를 활용한 정렬
std::vector<int> recSort(const std::vector<int>& arr) {
	if (arr.size() <= 1) return arr;

	std::vector<int> left, right;

	for (auto iter = arr.begin() + 1; iter < arr.end(); ++iter)
		if (*arr.begin() > *iter)	left.push_back(*iter);
		else						right.push_back(*iter);

	if (left.size()  >= 1) left  = recSort(left);
	if (right.size() >= 1) right = recSort(right);

	left.reserve(left.size() + right.size() + 1);
	left.push_back(*arr.begin());
	left.insert(left.end(), right.begin(), right.end());

	return left;
}

// 재귀 정렬 테스트
void test1() {
	std::vector<int> arr = generateRandomVector(1000);
	totalAllocated = 0;

	auto start = std::chrono::high_resolution_clock::now();
	std::vector<int> sArr = recSort(arr);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = end - start;

	// for (int i : sArr) std::cout << i << ' ';
	std::cout << "\n" << duration.count() << " ms";
	std::cout << "\n" << totalAllocated << " bytes\n";
}

// std::sort 테스트
void test2() {
	std::vector<int> arr = generateRandomVector(1000);
	totalAllocated = 0;

	auto start = std::chrono::high_resolution_clock::now();
	std::sort(arr.begin(), arr.end());
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = end - start;

	// for (int i : arr) std::cout << i << ' ';
	std::cout << "\n" << duration.count() << " ms";
	std::cout << "\n" << totalAllocated << " bytes\n";
}

int main() {
	test1();
	test2();
}