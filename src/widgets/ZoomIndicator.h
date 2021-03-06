/*
 * Copyright (C) 2020 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef KIMAGEANNOTATOR_ZOOMINDICATOR_H
#define KIMAGEANNOTATOR_ZOOMINDICATOR_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QAction>

#include "CustomSpinBox.h"
#include "src/common/helper/IconLoader.h"
#include "src/common/provider/ScaledSizeProvider.h"

namespace kImageAnnotator {

class ZoomIndicator : public QWidget
{
Q_OBJECT
public:
	explicit ZoomIndicator(QWidget *parent);
	~ZoomIndicator() override;
	void setZoomValue(double value);

signals:
	void zoomValueChanged(double zoomLevel);

private:
	QHBoxLayout *mLayout;
	QLabel *mLabel;
	CustomSpinBox *mSpinBox;
	QAction *mZoomInAction;
	QAction *mZoomOutAction;
	QAction *mResetZoomAction;

	void init();

private slots:
	void notifyZoomValueChanged(double value);
	void zoomIn();
	void zoomOut();
	void resetZoomOut();
	QString getToolTip() const;
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_ZOOMINDICATOR_H
