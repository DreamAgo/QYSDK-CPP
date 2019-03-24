#pragma once

class QYInfoAnalyze
{
	private:
		typedef struct {
			string key;
			string value;
		} info;
		std::vector<info> infoList;
		//infoList infoList;

	public:
		QYInfoAnalyze() {}
		QYInfoAnalyze(string msg) {
			write(msg);
		}
		~QYInfoAnalyze()
		{
			this->clear();
		}

		/* ��� */
		void clear();

		/**
		 * д��
		 * @param	string	msg		��Ϣ��
		 * @return	bool	д����
		 */
		bool write(string msg);

		/**
		 * ��ӵ���
		 * @param	string	key
		 * @param	string	value
		 */
		void addSingle(string key, string value);

		/**
		 * ��ȡ
		 * @param	string	key
		 * @return	string	value
		 */
		string read(string key);

		/**
		 * ���
		 * @return	string	��Ϣ����
		 */
		string print();

		/**
		 * ɾ������
		 * @param	string	key
		 * @return	bool	ɾ�����
		 */
		bool delSingle(string key);
};