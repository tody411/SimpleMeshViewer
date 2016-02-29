
/*!
  \file     ImportLabelDataCommand.cpp
  \author       Tody
  ImportLabelDataCommand definition.
  date      2016/02/27
*/

#include "ImportLabelDataCommand.h"


#include <QFileDialog>
#include <fstream>

void ImportLabelDataCommand::doImp ()
{
    if ( _inputFile == "" )
    {
        QFileDialog().setDirectory ( _scene->project()->dataDir() );

        _inputFile = QFileDialog::getOpenFileName ( nullptr,
                     "Import Label Data", QString(), "Label Data (*.dat)" );
    }

    if ( _inputFile == "" ) return;

    std::ifstream ifs ( _inputFile.toStdString() );

    int numFaces = _scene->mesh()->numFaces();

    std::vector<int> faceLabels ( numFaces );

    for ( int fi = 0; fi < numFaces; fi++ )
    {
        ifs >> faceLabels[fi];
    }

    _scene->labelData()->setFaceLabelData ( faceLabels );

    _inputFile = "";
}
