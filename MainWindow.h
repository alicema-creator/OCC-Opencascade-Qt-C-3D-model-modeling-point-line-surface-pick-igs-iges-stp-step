#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"


#include "occview.h"



#include "QMenu"
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <qDebug>

#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include "AIS_Shape.hxx"
#include <BRep_Tool.hxx>
#include <XBRepMesh.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <GCPnts_TangentialDeflection.hxx>
#include <TopExp_Explorer.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <AIS_Triangulation.hxx>
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
#include <IGESControl_Controller.hxx>
#include <IGESControl_Writer.hxx>
#include <IGESControl_Reader.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS.hxx>
#include <Graphic3d_CView.hxx>
#include <MeshVS_Mesh.hxx>
#include <IGESCAFControl_Writer.hxx>
#include <OSD_Path.hxx>
#include <RWStl.hxx>
#include <XSDRAWSTLVRML_DataSource.hxx>
#include <StlAPI.hxx>
#include <AIS_Shape.hxx>
#include <AIS_InteractiveContext.hxx>
#include <StlAPI_Reader.hxx>
#include <V3d_Viewer.hxx>
#include <V3d_View.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <WNT_Window.hxx>
#include <Aspect_Handle.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepMesh_Context.hxx>
#include <BRepMesh_FaceDiscret.hxx>
#include <BRepMesh_DelabellaMeshAlgoFactory.hxx>
#include <StlAPI_Writer.hxx>
#include <MeshVS_DataSource.hxx>
#include <MeshVS_MeshPrsBuilder.hxx>
#include <MeshVS_DataSource3D.hxx>
#include <AIS_ViewCube.hxx>
#include <IntCurvesFace_ShapeIntersector.hxx>
#include <AIS_Point.hxx>
#include <Geom_CartesianPoint.hxx>
#include <Prs3d_pointAspect.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>
#include <Prs3d_LineAspect.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>
#include <Geom_Surface.hxx>
#include <gp_Pnt.hxx>
#include <BRepTools.hxx>
#include <MeshVS_DataMapOfIntegerColor.hxx>
#include <MeshVS_NodalColorPrsBuilder.hxx>
#include <IMeshData_Status.hxx>
#include <IMeshTools_Parameters.hxx>
#include <gp_Pnt.hxx> 
#include <gp_Pln.hxx> 
#include <BRep_Tool.hxx> 
#include <TopoDS.hxx> 
#include <TopoDS_Edge.hxx> 
#include <TopoDS_Wire.hxx> 
#include <TopoDS_Face.hxx> 
#include <BRepBuilderAPI_MakeEdge.hxx> 
#include <BRepBuilderAPI_MakeWire.hxx> 
#include <BRepBuilderAPI_MakeFace.hxx> 
#include <BRepPrimAPI_MakeBox.hxx> 
#include <BRepPrimAPI_MakeCone.hxx> 
#include <BRepPrimAPI_MakeCylinder.hxx> 
#include <BRepPrimApI_MakeSphere.hxx> 
#include <XBRepMesh.hxx> 
#include <TopExp_Explorer.hxx> 
#include <Poly_Triangulation.hxx> 
#include <TShort_Array1OfShortReal.hxx> 

#include <BRepBndLib.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <gp_Pnt.hxx>
#include <Prs3d_Arrow.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <AIS_Shape.hxx>
#include <AIS_InteractiveContext.hxx>
#include <Standard_Macro.hxx>
#include <AIS_InteractiveObject.hxx>
#include <Graphic3d_Group.hxx>
#include <Prs3d_Arrow.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <GCPnts_AbscissaPoint.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <GCPnts_AbscissaPoint.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <set>
#include <iostream>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::MainWindowClass ui;

    occview* occView;

private:
	void InitMenu();
	TopoDS_Shape createBox();
	TopoDS_Shape createSphere();



private slots:
	void trigerMenu(QAction* action);


};
