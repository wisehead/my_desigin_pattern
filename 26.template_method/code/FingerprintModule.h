#ifndef __FINGERPRINTMODULE_H__
#define __FINGERPRINTMODULE_H__

#include <stdio.h>

// 基类
class FingerprintModule
{
public:
	FingerprintModule(){}
	void getImage(){
		//printf("采指纹图像\n");
		printf("get finger graph.\n");
	}
	void output(){
		printf("finger graph process completed.\n\n");
	}
	virtual bool isSafeMode() = 0;
	virtual void processImage() = 0;
	// 加解密
	virtual void encrypt() = 0;
	virtual void decrypt() = 0;

	// 模板方法
	void algorithm(){
		// 1.采图
		getImage();
		// 2.安全模式下加密和解密
		if (isSafeMode()){
			// 2.1. 加密
			encrypt();
			// 2.2. 解密
			decrypt();
		}
		// 3.处理Image
		processImage();
		// 4.处理结果
		output();
	}
};

// 派生类
class FingerprintModuleA :public FingerprintModule
{
public:
	FingerprintModuleA(){}
	void processImage(){
		//printf("使用 第一代版本算法 处理指纹图像\n");
		printf("use gen1 alg to process finger graph.\n");
	}
	bool isSafeMode(){
		//printf("安全模式\n");
		printf("safe mod.......\n");
		return true;
	}
	void encrypt(){
		//`printf("使用RSA密钥加密\n");
		printf("use RSA to encrypt.\n");
	}
	void decrypt(){
		//printf("使用RSA密钥解密\n");
		printf("use RSA to decrypt\n");
	}
};

// 派生类
class FingerprintModuleB :public FingerprintModule
{
public:
	FingerprintModuleB(){}
	void processImage(){
		//printf("使用 第二代版本算法 处理指纹图像\n");
		printf("use gen2 alg. to process finger graph.\n");
	}
	bool isSafeMode(){
		//printf("非安全模式\n");
		printf("unsafe mode....\n");
		return false;
	}
	void encrypt(){}
	void decrypt(){}
};

// 派生类
class FingerprintModuleC :public FingerprintModule
{
public:
	FingerprintModuleC(){}
	void processImage(){
		//printf("使用 第一代版本算法 处理指纹图像\n");
		printf("use gen1 alg. to process finger graph.\n");
	}
	bool isSafeMode(){
		//printf("安全模式\n");
		printf("safe mode.\n");
		return true;
	}
	void encrypt(){
		//printf("使用DH密钥加密\n");
		printf("use DH to encrypt.\n");
	}
	void decrypt(){
		//`printf("使用DH密钥解密\n");
		printf("use DH to decrypt.\n");
	}
};

#endif  //__FINGERPRINTMODULE_H__
