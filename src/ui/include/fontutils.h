
/*
 * Copyright (C) 2021 Anton Filimonov and other contributors
 *
 * This file is part of klogg.
 *
 * klogg is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * klogg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with klogg.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KLOGG_FONTUTILS
#define KLOGG_FONTUTILS

#include <numeric>

#include <QFontDatabase>

class FontUtils {
  public:
    static QStringList availableFonts()
    {
        QStringList fixedFamiles;

        QFontDatabase database;

        // We only show the fixed fonts
        auto families = database.families();
        for ( const auto& family : qAsConst( families ) ) {
            if ( database.isFixedPitch( family ) )
                fixedFamiles << family;
        }

        return fixedFamiles;
    }

    static QList<int> availableFontSizes( const QString& family )
    {
        QFontDatabase database;
        auto sizes = database.pointSizes( family, "" );
        if ( sizes.empty() ) {
            sizes = QFontDatabase::standardSizes();
        }

        return sizes;
    }
};

#endif