#include "MainWindow.h"

#include <BRep_Builder.hxx>
#include <StepData_StepModel.hxx>
#include <STEPControl_Reader.hxx>
#include <TCollection_AsciiString.hxx>
#include <XSControl_Controller.hxx>
#include <Interface_Static.hxx>
#include <Transfer_TransientProcess.hxx>

#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Sphere.hxx>

#include <Poly_Polygon3D.hxx>
#include <Poly_Triangulation.hxx>

#include <TopTools_ListIteratorOfListOfShape.hxx>
#include <TopTools_HSequenceOfShape.hxx>

#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>

#include <IGESControl_Controller.hxx>
#include <IGESControl_Writer.hxx>
#include <IGESControl_Reader.hxx>

#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS.hxx>

#include <BRep_Tool.hxx>
#include <XBRepMesh.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>

#include <BRepAdaptor_Curve.hxx>
#include <GCPnts_TangentialDeflection.hxx>
#include <TopExp_Explorer.hxx>
#include <Standard_TypeDef.hxx>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);


	occView = new occview(this);
	setCentralWidget(occView);
	//ui.frame->layout()->addWidget(occView);
	InitMenu();
}



void MainWindow::InitMenu()
{
	QMenuBar* menuBar = ui.menuBar;
	QMenu* menuCreate = menuBar->addMenu(tr("&Create"));
	menuCreate->addAction(tr("&Box"));
	menuCreate->addAction(tr("&Sphere"));
	connect(menuBar, SIGNAL(triggered(QAction*)), this, SLOT(trigerMenu(QAction*)));


}

TopoDS_Shape MainWindow::createBox()
{
	return BRepPrimAPI_MakeBox(10.0, 10.0, 10.0).Shape();
}

TopoDS_Shape MainWindow::createSphere()
{
	return BRepPrimAPI_MakeSphere(10.0).Shape();
}

void MainWindow::trigerMenu(QAction* action)
{
	if (action->text() == "&Box")
	{
		TopoDS_Shape box = createBox();
		Handle(AIS_Shape) aisBox = new AIS_Shape(box);
		occView->GetInteractiveContext()->Display(aisBox, Standard_True);
		occView->GetView()->FitAll();
		//occView->selectMode(aisBox);
		//occView->setHightStyle();
		//occView->setSelectStyle();

	}
	else if (action->text() == "&Sphere")
	{
		TopoDS_Shape sphere = createSphere();
		Handle(AIS_Shape) aisSphere = new AIS_Shape(sphere);
		occView->GetInteractiveContext()->Display(aisSphere, Standard_True);
		occView->GetView()->FitAll();
	}
	else
	{
		QMessageBox::warning(this, tr("Warning"), action->text());
	}
}
