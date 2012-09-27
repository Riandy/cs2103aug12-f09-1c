#include "GuiType.h"

GuiType::GuiType(bool flag)
{
    setStandardView(flag);
}

void GuiType:: showGui()
{
    if (standardViewFlag)
    {
        standard.show();
    }
    else
    {
        seample.show();
    }
}

void GuiType::setStandardView (bool flag)
{
    standardViewFlag = flag;
}

bool GuiType::isStandardView()
{
    return standardViewFlag;
}
