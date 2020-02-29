#include "Originator.h"
#include "Memento.h"
#include "CodeManager.h"

int main()
{
	CodeManager *Jungle = new CodeManager();

	CodeVersion* codeVer = new CodeVersion(1001, "2019-11-03", "Initial version");

	// 提交初始版本
	printf("commit initial version:\n");
	Jungle->commit(codeVer->save());

	// 修改一个版本，增加了日志功能
	printf("\ncommit one version, add logging function.\n");
	codeVer->setVersion(1002);
	codeVer->setDate("2019-11-04");
	codeVer->setLabel("Add log funciton");
	Jungle->commit(codeVer->save());

	// 修改一个版本，增加了Qt图片浏览器
	//printf("\n提交一个版本，增加了Qt图片浏览器:\n");
	printf("\ncommit one version, add QT Picture Browser.\n");
	codeVer->setVersion(1003);
	codeVer->setDate("2019-11-05");
	codeVer->setLabel("Add Qt Image Browser");
	Jungle->commit(codeVer->save());

	// 查看提交历史
	//printf("\n查看提交历史\n");
	printf("\nlook up commit history\n");
	Jungle->codeLog();

	// 回退到上一个版本
	//printf("\n回退到上一个版本\n");
	printf("\nroll back to last version\n");
	codeVer->restore(Jungle->switchToPointedVersion(1));

	// 查看提交历史
	//printf("\n查看提交历史\n");
	printf("\nlookup commit history\n");
	Jungle->codeLog();

	printf("\n\n");
	system("pause");
	return 0;
}
