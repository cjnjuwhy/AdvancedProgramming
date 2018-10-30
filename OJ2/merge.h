#pragma once

template<class T>
T* merge(T* array_1, size_t size_1, T* array_2, size_t size_2) {
	T* ans = new T[size_1 + size_2];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < size_1 && j < size_2) {
		if (array_1[i] < array_2[j]) {
			ans[k++] = array_1[i++];
		}
		else {
			ans[k++] = array_2[j++];
		}
	}
	for (; i < size_1; i++) {
		ans[k++] = array_1[i];
	}
	for (; j < size_2; j++) {
		ans[k++] = array_2[j];
	}
	return ans;
}