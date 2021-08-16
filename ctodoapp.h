#pragma once

#include <QMainWindow>
#include <QStringListModel>
#include <QListView>
#include <QPushButton>

class CToDoApp : public QMainWindow
{
	Q_OBJECT

public:
	CToDoApp();

protected slots:
	void OnAdd();
	void OnTodoDelete();
	void OnCompletedDelete();

private:
	QListView* m_pTodo = nullptr;
	QListView* m_pCompleted = nullptr;

	QPushButton* m_pAdd = nullptr;
	QPushButton* m_pTodoDelete = nullptr;
	QPushButton* m_pCompletedDelete = nullptr;
};

