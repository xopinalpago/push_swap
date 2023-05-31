/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:48:40 by rmeriau           #+#    #+#             */
/*   Updated: 2023/05/24 11:44:27 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void sa(int* array, int size) {
    if (size >= 2) {
        int temp = array[0];
        array[0] = array[1];
        array[1] = temp;
    }
}

void pa(int* src, int* dst, int* size_src, int* size_dst) {
    if (*size_src > 0) {
        dst[*size_dst] = src[0];
        (*size_dst)++;
        for (int i = 0; i < *size_src - 1; i++) {
            src[i] = src[i + 1];
        }
        (*size_src)--;
    }
}

void ra(int* array, int size) {
    if (size >= 2) {
        int temp = array[0];
        for (int i = 0; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        array[size - 1] = temp;
    }
}

void quickSort(int* array, int size) {
    if (size < 2) {
        return;
    }

    int pivot = array[0];
    int size_less = 0;
    int size_greater = 0;
    int less[size];
    int greater[size];

    for (int i = 1; i < size; i++) {
        if (array[i] < pivot) {
            less[size_less] = array[i];
            size_less++;
        } else {
            greater[size_greater] = array[i];
            size_greater++;
        }
    }

    quickSort(less, size_less);
    quickSort(greater, size_greater);

    for (int i = 0; i < size_less; i++) {
        array[i] = less[i];
        printf("pb\n");
    }

    array[size_less] = pivot;
    printf("ra\n");

    for (int i = 0; i < size_greater; i++) {
        array[i + size_less + 1] = greater[i];
        printf("pb\n");
    }
}

int main() {
    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);

    quickSort(array, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
