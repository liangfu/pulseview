/*
 * This file is part of the PulseView project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
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
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PULSEVIEW_PV_PROP_ENUM_HPP
#define PULSEVIEW_PV_PROP_ENUM_HPP

#include <utility>
#include <vector>

#include "property.hpp"

#include <QMetaType>

using std::pair;
using std::vector;

Q_DECLARE_METATYPE(Glib::VariantBase);

class QComboBox;
class QLabel;
class QSlider;

namespace pv {
namespace prop {

class Enum : public Property
{
	Q_OBJECT;

public:
	Enum(QString name, QString desc,
		vector<pair<Glib::VariantBase, QString> > values,
		Getter getter, Setter setter);

	virtual ~Enum() = default;

	QWidget* get_widget(QWidget *parent, bool auto_commit);
	void update_widget();

	void commit();

private Q_SLOTS:
	void on_current_index_changed(int);
	void on_value_changed(int);

private:
	const vector< pair<Glib::VariantBase, QString> > values_;
	bool is_range_;

	QComboBox *selector_;

	QWidget *slider_layout_widget_;
	QSlider *slider_;
	QLabel *slider_label_;
};

}  // namespace prop
}  // namespace pv

#endif // PULSEVIEW_PV_PROP_ENUM_HPP
