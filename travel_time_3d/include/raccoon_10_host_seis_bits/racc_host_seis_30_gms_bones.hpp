#pragma once
#ifndef RACC_HOST_SEIS_GMSREADER_H_BONES
#define RACC_HOST_SEIS_GMSREADER_H_BONES
#include "racc_host_seis_11_fun_meat.hpp"
namespace racc
{
	struct GmsFileHeader
	{
		short int FileFormat; // �������ͺ�
		char ModelName[64];	  // ģ����
		short int Year;		  // ģ������ʱ�䣬��
		char Mouth;			  // ģ������ʱ�䣬��
		char Day;			  // ģ������ʱ�䣬��
		char Hour;			  // ģ������ʱ�䣬ʱ
		char Minutes;		  // ģ������ʱ�䣬��
		char Seconds;		  // ģ������ʱ�䣬��
		char type;			  // 1 = ����
		short int ParaNum;	  // ��������
		float x0;			  // x�������
		float y0;			  // y�������
		float z0;			  // z�������
#ifdef __linux__
		int nx; // x������
		int ny; // y������
		int nz; // z������
#endif
#ifdef _WIN32
		long nx; // x������
		long ny; // y������
		long nz; // z������
#endif
		float dx;			// x������
		float dy;			// y������
		float dz;			// z������
		char Reserved[127]; // �����ռ�
	};

	struct GmsDataHeader
	{
		char dataName[64]; // ����������
		char Reserved[64]; // �����ռ�
	};

	class CGmsReader2D
	{
	private:
		int ParaOrder = 0;
		int ParaNum;
		string Path;
		void ReadGMSModel2D();

	public:
		// fmat ParaMesh;
		fcube ParaGrid;
		fmat AllData;
		MeshFrame mesh;

	public:
		CGmsReader2D(string path);
		fmat ReadGMSByOrder();
		ffield ReadGMSByOrderToField();
#ifdef RACC_DEBUG
		void PrintInfo();
#endif
	};

	class CGmsReader
	{
	private:
		int ParaOrder = 0;
		int ParaNum;
		std::string Path;
		void ReadGMSModel();

	public:
		fmat AllData;
		GridFrame grid;

	public:
		CGmsReader(std::string path);
		template <typename T = float>
		Cube<T> ReadGMSByOrderToCube();
		template <typename T = float>
		void ReadGMSByOrderToField(Field<T> &field_obj);
#ifdef RACC_USE_ARMA
		template <typename T>
		arma::Grid<T> ReadGMSByOrderToArmaGrid();
#endif

#ifdef RACC_DEBUG
		void PrintInfo();
#endif
	};
}
#endif
