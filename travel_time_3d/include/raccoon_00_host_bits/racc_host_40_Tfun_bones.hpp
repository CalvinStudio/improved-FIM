#pragma once
#ifndef RACC_TFUN_BONES
#define RACC_TFUN_BONES
//**********************************Developer******************************************
// 2020.04.10 BY CAIWEI CALVIN CAI
//*************************************************************************************
#include "racc_host_31_Tmemory_meat.hpp"
//************************************ARRAY********************************************
namespace racc
{
	//�������еĽ�Сֵ
	template <typename eT>
	eT min(eT a, eT b);
	//�������е���Сֵ
	template <typename eT>
	eT min(eT a, eT b, eT c);
	//�������еĽϴ�ֵ
	template <typename eT>
	eT max(eT a, eT b);
	//�������е����ֵ
	template <typename eT>
	eT max(eT a, eT b, eT c);
	//һά��������Сֵ
	template <typename eT>
	eT min(eT *a, int l); //һά��������Сֵ
	//һά���������ֵ
	template <typename eT>
	eT max(eT *a, int l); //һά���������ֵ
	//��ά��������Сֵ
	template <typename eT>
	eT min(eT **a, uint32_t n_rows, uint32_t n_cols);
	//��ά���������ֵ
	template <typename eT>
	eT max(eT **a, uint32_t n_rows, uint32_t n_cols);
	//��ά��������Сֵ
	template <typename eT>
	eT min(eT ***a, uint32_t n_rows, uint32_t n_cols, uint32_t n_slices);
	//��ά���������ֵ
	template <typename eT>
	eT max(eT ***a, uint32_t n_rows, uint32_t n_cols, uint32_t n_slices);
	//һά������Ѱ��Сֵ�Ͷ�Ӧ�ĵ�λ��
	template <typename eT>
	void min(eT *a, uint64_t l, eT &min_val, uint64_t &pos);
	//һά������Ѱ���ֵ�Ͷ�Ӧ�ĵ�λ��
	template <typename eT>
	void max(eT *a, uint64_t l, eT &max_val, uint64_t &pos);
	//��ά������Ѱ��Сֵ�Ͷ�Ӧ�ĵ�λ��
	template <typename eT>
	void min(eT **a, int n_rows, uint32_t n_cols, eT *min_val, uint32_t &pos_x, uint32_t &pos_y);
	//��ά������Ѱ���ֵ�Ͷ�Ӧ�ĵ�λ��
	template <typename eT>
	void max(eT **a, uint32_t n_rows, uint32_t n_cols, eT *max_val, uint32_t &pos_x, uint32_t &pos_y);
	//����1D�������ֵ����Сֵ
	template <typename eT>
	eT MinAbs(eT *a, uint64_t l);
	//����1D�������ֵ�����ֵ
	template <typename eT>
	eT MaxAbs(eT *a, uint64_t l);
	//����2D�������ֵ����Сֵ
	template <typename eT>
	eT MinAbs(eT **a, uint32_t n_rows, uint32_t n_cols);
	//����2D�������ֵ�����ֵ
	template <typename eT>
	eT MaxAbs(eT **a, uint32_t n_rows, uint32_t n_cols);
	template <typename eT>
	void limit(eT &a, double lb, double rb);
	template <typename eT>
	void UnitVec(eT &a, eT &b);
	//*********************************************************************************
	//***********************Array transformation and operation************************
	// One dimensional array to three dimensional array.
	template <typename T>
	T ***TransArray1DTo3D(T *a_1, uint64_t l, uint32_t n_rows, uint32_t n_cols, uint32_t n_slices);
	// Three dimensional array to one dimensional array.
	template <typename T>
	T *TransArray3DTo1D(T ***a_3, uint32_t n_rows, uint32_t n_cols, uint32_t n_slices);
	//�������С��������,����ԭ����
	template <typename T>
	void Sort(T *&a, uint64_t l);
	//����ArrayIn�Ĳ�֣����ArrayOut
	template <typename T>
	void Diff(T *&a_i, uint64_t l, T di, T *a_o);
	template <typename T>
	void Swap(T &a, T &b);
	// Full Permutation
	template <typename T>
	bool NextPermutation(T *p, uint32_t n);
	// Show Permutation
	template <typename T>
	void ShowPermutation(T *p, uint32_t n);
	//*********************************************************************************
}
#endif