
//! MenuGroup definition.
/*!
  \file     MenuGroup.h
  \author   Tody
  \date     2015/12/16
*/

#ifndef COMMANDMENUE_H
#define COMMANDMENUE_H

#include <QMenu>
#include <QAction>

#include "BaseCommand.h"

//! MenuGroup implementation.
class MenuGroup : public QMenu
{
    Q_OBJECT
public :
    //! Constructor.
    MenuGroup ( const QString& name, QWidget* parent = nullptr )
        : _name ( name ), QMenu ( name, parent )
    {
    }

    //! Destructor.
    virtual ~MenuGroup() {}

    //! Add command to the menu group.
    void addCommand ( BaseCommand* command );

private:
    //! Menu group name.
    QString _name;

};

#endif

