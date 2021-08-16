#include "ctodoapp.h"

#include <QToolBar>
#include <QLabel>
#include <QLayout>

CToDoApp::CToDoApp()
{
	QWidget* pWidget = new QWidget(this);
	pWidget->setStyleSheet("background: #e8e8e8;");
	setCentralWidget(pWidget);

	QVBoxLayout* pMainLayout = new QVBoxLayout();
	pWidget->setLayout(pMainLayout);

	QLabel* pTitle = new QLabel("To-Do", this);
	pMainLayout->addWidget(pTitle);
	pTitle->setAlignment(Qt::AlignCenter);
	pTitle->setStyleSheet("font-size: 30pt; margin: 10%;");

	QHBoxLayout* pLabelLayout = new QHBoxLayout();
	pMainLayout->addLayout(pLabelLayout);

	QHBoxLayout* pListLayout = new QHBoxLayout();
	pMainLayout->addLayout(pListLayout);

	QHBoxLayout* pButtonLayout = new QHBoxLayout();
	pMainLayout->addLayout(pButtonLayout);

	QLabel* plTodo = new QLabel("Pending", this);
	plTodo->setStyleSheet("font-size: 15pt;");
	pLabelLayout->addWidget(plTodo);

	QLabel* plCompleted = new QLabel("Completed", this);
	plTodo->setStyleSheet("font-size: 15pt;");
	pLabelLayout->addWidget(plCompleted);

	m_pAdd = new QPushButton("Add", this);
	m_pTodoDelete = new QPushButton("Remove from Pending Tasks", this);
	m_pCompletedDelete = new QPushButton("Remove from Completed Tasks", this);

	connect(m_pAdd, &QPushButton::clicked, this, &CToDoApp::OnAdd);
	connect(m_pTodoDelete, &QPushButton::clicked, this, &CToDoApp::OnTodoDelete);
	connect(m_pCompletedDelete, &QPushButton::clicked, this, &CToDoApp::OnCompletedDelete);

	pButtonLayout->addWidget(m_pAdd);
	pButtonLayout->addWidget(m_pTodoDelete);
	pButtonLayout->addWidget(m_pCompletedDelete);

	m_pTodo = new QListView(this);
	m_pTodo->setDragEnabled(true);
	m_pTodo->setAcceptDrops(true);
	m_pTodo->setDropIndicatorShown(true);
	m_pTodo->setDefaultDropAction(Qt::MoveAction);
	pListLayout->addWidget(m_pTodo);

	m_pCompleted = new QListView(this);
	m_pCompleted->setDragEnabled(true);
	m_pCompleted->setAcceptDrops(true);
	m_pCompleted->setDropIndicatorShown(true);
	m_pCompleted->setDefaultDropAction(Qt::MoveAction);
	pListLayout->addWidget(m_pCompleted);

	m_pTodo->setModel(new QStringListModel());
	m_pCompleted->setModel(new QStringListModel());

	m_pTodo->setStyleSheet
	("QListView {font-size: 15pt; font-weight: bold;}"
	"QListView::item {background-color: #de0404; padding: 10%;"
	"border: #b81807}"
	"QListView::item::hover {background-color: #b81807}");

	m_pCompleted->setStyleSheet
	("QListView {font-size: 15pt; font-weight: bold;}"
		"QListView::item {background-color: #04db41; padding: 10%;"
		"border: #1ab045}"
		"QListView::item::hover {background-color: #1ab045}");
}

void CToDoApp::OnAdd()
{
	m_pTodo->model()->insertRow(m_pTodo->model()->rowCount());
	QModelIndex oIndex = m_pTodo->model()->index(m_pTodo->model()->rowCount() - 1, 0);

	m_pTodo->edit(oIndex);
}

void CToDoApp::OnTodoDelete()
{
	QModelIndex oIndex = m_pTodo->currentIndex();

	m_pTodo->model()->removeRow(oIndex.row());
}

void CToDoApp::OnCompletedDelete()
{
	QModelIndex oIndex = m_pCompleted->currentIndex();
	
	m_pCompleted->model()->removeRow(oIndex.row());
}
