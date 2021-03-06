#include "Wt/WAbstractGLImplementation"

namespace Wt {

#ifdef WT_WGLWIDGET_DEBUG
  bool WAbstractGLImplementation::debugging_ = true;
#endif

WAbstractGLImplementation::WAbstractGLImplementation(WGLWidget *glInterface)
  : glInterface_(glInterface),
    updateGL_(false),
    updateResizeGL_(false),
    updatePaintGL_(false),
    webglNotAvailable_(this, "webglNotAvailable")
{
  webglNotAvailable_.connect(glInterface_, &WGLWidget::webglNotAvailable);
}

void WAbstractGLImplementation::repaintGL(WFlags<WGLWidget::ClientSideRenderer> which)
{
  if (which & WGLWidget::PAINT_GL)
    updatePaintGL_ = true;
  if (which & WGLWidget::RESIZE_GL)
    updateResizeGL_ = true;
  if (which & WGLWidget::UPDATE_GL)
    updateGL_ = true;
}

void WAbstractGLImplementation::layoutSizeChanged(int width, int height)
{
  renderWidth_ = width;
  renderHeight_ = height;
  sizeChanged_ = true;
}

}
