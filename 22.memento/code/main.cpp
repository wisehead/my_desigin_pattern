#include "Originator.h"
#include "Memento.h"
#include "CodeManager.h"

int main()
{
	CodeManager *Jungle = new CodeManager();

	CodeVersion* codeVer = new CodeVersion(1001, "2019-11-03", "Initial version");

	// �ύ��ʼ�汾
	printf("commit initial version:\n");
	Jungle->commit(codeVer->save());

	// �޸�һ���汾����������־����
	printf("\ncommit one version, add logging function.\n");
	codeVer->setVersion(1002);
	codeVer->setDate("2019-11-04");
	codeVer->setLabel("Add log funciton");
	Jungle->commit(codeVer->save());

	// �޸�һ���汾��������QtͼƬ�����
	//printf("\n�ύһ���汾��������QtͼƬ�����:\n");
	printf("\ncommit one version, add QT Picture Browser.\n");
	codeVer->setVersion(1003);
	codeVer->setDate("2019-11-05");
	codeVer->setLabel("Add Qt Image Browser");
	Jungle->commit(codeVer->save());

	// �鿴�ύ��ʷ
	//printf("\n�鿴�ύ��ʷ\n");
	printf("\nlook up commit history\n");
	Jungle->codeLog();

	// ���˵���һ���汾
	//printf("\n���˵���һ���汾\n");
	printf("\nroll back to last version\n");
	codeVer->restore(Jungle->switchToPointedVersion(1));

	// �鿴�ύ��ʷ
	//printf("\n�鿴�ύ��ʷ\n");
	printf("\nlookup commit history\n");
	Jungle->codeLog();

	printf("\n\n");
	system("pause");
	return 0;
}
