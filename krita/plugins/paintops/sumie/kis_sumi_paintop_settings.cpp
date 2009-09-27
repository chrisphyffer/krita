/*
 *  Copyright (c) 2008 Boudewijn Rempt <boud@valdyas.org>
 *  Copyright (c) 2008 Lukáš Tvrdý <lukast.dev@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#include "kis_sumi_paintop_settings.h"

#include "kis_sumi_paintop_settings_widget.h"
#include "kis_sumi_ink_option.h"
#include "kis_sumi_shape_option.h"

KisSumiPaintOpSettings::KisSumiPaintOpSettings()
    : m_options(0)
{
}

KisPaintOpSettingsSP KisSumiPaintOpSettings::clone() const
{
    KisPaintOpSettings* settings =
        static_cast<KisPaintOpSettings*>( m_options->configuration() );
    return settings;
}


bool KisSumiPaintOpSettings::paintIncremental()
{
    return false;
}

void KisSumiPaintOpSettings::fromXML(const QDomElement& elt)
{
    // First, call the parent class fromXML to make sure all the
    // properties are saved to the map
    KisPaintOpSettings::fromXML( elt );

    // Then load the properties for all widgets
    m_options->setConfiguration( this );
}

void KisSumiPaintOpSettings::toXML(QDomDocument& doc, QDomElement& rootElt) const
{
    // First, make sure all the option widgets have saved their state
    // to the property configuration
    KisPropertiesConfiguration * settings = m_options->configuration();

    // Then call the parent class fromXML
    settings->KisPropertiesConfiguration::toXML( doc, rootElt );

    delete settings;
}


QList<float> KisSumiPaintOpSettings::curve() const
{
    return m_options->m_sumiInkOption->curve();
}

int KisSumiPaintOpSettings::radius() const
{
    return m_options->m_sumiShapeOption->radius();
}

double KisSumiPaintOpSettings::sigma() const
{
    return m_options->m_sumiShapeOption->sigma();
}

bool KisSumiPaintOpSettings::mousePressure() const
{
    return m_options->m_sumiShapeOption->mousePressure();
}

int KisSumiPaintOpSettings::brushDimension() const
{
    return m_options->m_sumiShapeOption->brushDimension();
}

int KisSumiPaintOpSettings::inkAmount() const
{
    return m_options->m_sumiInkOption->inkAmount();
}

double KisSumiPaintOpSettings::shearFactor() const
{
    return m_options->m_sumiShapeOption->shearFactor();
}

double KisSumiPaintOpSettings::randomFactor() const
{
    return m_options->m_sumiShapeOption->randomFactor();
}

double KisSumiPaintOpSettings::scaleFactor() const
{
    return m_options->m_sumiShapeOption->scaleFactor();
}

bool KisSumiPaintOpSettings::useSaturation() const
{
    return m_options->m_sumiInkOption->useSaturation();
}

bool KisSumiPaintOpSettings::useOpacity() const
{
    return m_options->m_sumiInkOption->useOpacity();
}

bool KisSumiPaintOpSettings::useWeights() const
{
    return m_options->m_sumiInkOption->useWeights();
}

int KisSumiPaintOpSettings::pressureWeight() const
{
    return m_options->m_sumiInkOption->pressureWeight();
}

int KisSumiPaintOpSettings::bristleLengthWeight() const
{
    return m_options->m_sumiInkOption->bristleLengthWeight();
}

int KisSumiPaintOpSettings::bristleInkAmountWeight() const
{
    return m_options->m_sumiInkOption->bristleInkAmountWeight();
}

int KisSumiPaintOpSettings::inkDepletionWeight() const
{
    return m_options->m_sumiInkOption->inkDepletionWeight();
}

