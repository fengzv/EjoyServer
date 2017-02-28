#pragma once
#include <map>




/*
* ���������
*
*
*/

class CDataProxyPlugin;

class CPluginMgr
{
public:
	CPluginMgr(void);
	~CPluginMgr(void);

	typedef std::map<std::string,CDataProxyPlugin*>::iterator mapDBPIter;

	/*
	 * @desc ����dataproxy���
	 * @param plugin_dir �������Ŀ¼
	 * @return ��������Ŀ
	 *	
	 */
	int LoadPlugins(const char* plugin_dir);
	

	/*
	 * @desc ��ò��
	 * @param sz_plugin_name �������
	 * @return dataproxy���
	 *	
	 */
	CDataProxyPlugin* GetPlugin(const char* sz_plugin_name);


private:

	std::map<std::string,CDataProxyPlugin*> m_mapPlugins;
};

