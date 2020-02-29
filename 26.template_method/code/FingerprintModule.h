#ifndef __FINGERPRINTMODULE_H__
#define __FINGERPRINTMODULE_H__

#include <stdio.h>

// ����
class FingerprintModule
{
public:
	FingerprintModule(){}
	void getImage(){
		//printf("��ָ��ͼ��\n");
		printf("get finger graph.\n");
	}
	void output(){
		printf("finger graph process completed.\n\n");
	}
	virtual bool isSafeMode() = 0;
	virtual void processImage() = 0;
	// �ӽ���
	virtual void encrypt() = 0;
	virtual void decrypt() = 0;

	// ģ�巽��
	void algorithm(){
		// 1.��ͼ
		getImage();
		// 2.��ȫģʽ�¼��ܺͽ���
		if (isSafeMode()){
			// 2.1. ����
			encrypt();
			// 2.2. ����
			decrypt();
		}
		// 3.����Image
		processImage();
		// 4.������
		output();
	}
};

// ������
class FingerprintModuleA :public FingerprintModule
{
public:
	FingerprintModuleA(){}
	void processImage(){
		//printf("ʹ�� ��һ���汾�㷨 ����ָ��ͼ��\n");
		printf("use gen1 alg to process finger graph.\n");
	}
	bool isSafeMode(){
		//printf("��ȫģʽ\n");
		printf("safe mod.......\n");
		return true;
	}
	void encrypt(){
		//`printf("ʹ��RSA��Կ����\n");
		printf("use RSA to encrypt.\n");
	}
	void decrypt(){
		//printf("ʹ��RSA��Կ����\n");
		printf("use RSA to decrypt\n");
	}
};

// ������
class FingerprintModuleB :public FingerprintModule
{
public:
	FingerprintModuleB(){}
	void processImage(){
		//printf("ʹ�� �ڶ����汾�㷨 ����ָ��ͼ��\n");
		printf("use gen2 alg. to process finger graph.\n");
	}
	bool isSafeMode(){
		//printf("�ǰ�ȫģʽ\n");
		printf("unsafe mode....\n");
		return false;
	}
	void encrypt(){}
	void decrypt(){}
};

// ������
class FingerprintModuleC :public FingerprintModule
{
public:
	FingerprintModuleC(){}
	void processImage(){
		//printf("ʹ�� ��һ���汾�㷨 ����ָ��ͼ��\n");
		printf("use gen1 alg. to process finger graph.\n");
	}
	bool isSafeMode(){
		//printf("��ȫģʽ\n");
		printf("safe mode.\n");
		return true;
	}
	void encrypt(){
		//printf("ʹ��DH��Կ����\n");
		printf("use DH to encrypt.\n");
	}
	void decrypt(){
		//`printf("ʹ��DH��Կ����\n");
		printf("use DH to decrypt.\n");
	}
};

#endif  //__FINGERPRINTMODULE_H__
