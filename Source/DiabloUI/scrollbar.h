#pragma once

#include <cstdint>

#include "DiabloUI/ui_item.h"
#include "engine/pcx_sprite.hpp"

namespace devilution {

extern std::optional<OwnedPcxSprite> ArtScrollBarBackground;
extern std::optional<OwnedPcxSprite> ArtScrollBarThumb;
extern std::optional<OwnedPcxSpriteSheet> ArtScrollBarArrow;
const Uint16 SCROLLBAR_BG_WIDTH = 25;

enum ScrollBarArrowFrame : uint8_t {
	ScrollBarArrowFrame_UP_ACTIVE,
	ScrollBarArrowFrame_UP,
	ScrollBarArrowFrame_DOWN_ACTIVE,
	ScrollBarArrowFrame_DOWN,
};

const Uint16 SCROLLBAR_ARROW_WIDTH = 25;

inline SDL_Rect UpArrowRect(const UiScrollbar *sb)
{
	SDL_Rect Tmp;
	Tmp.x = sb->m_rect.x;
	Tmp.y = sb->m_rect.y;
	Tmp.w = SCROLLBAR_ARROW_WIDTH;
	Tmp.h = static_cast<Uint16>(sb->m_arrow.frameHeight());

	return Tmp;
}

inline SDL_Rect DownArrowRect(const UiScrollbar *sb)
{
	SDL_Rect Tmp;
	Tmp.x = sb->m_rect.x;
	Tmp.y = static_cast<Sint16>(sb->m_rect.y + sb->m_rect.h - sb->m_arrow.frameHeight());
	Tmp.w = SCROLLBAR_ARROW_WIDTH,
	Tmp.h = static_cast<Uint16>(sb->m_arrow.frameHeight());

	return Tmp;
}

inline Uint16 BarHeight(const UiScrollbar *sb)
{
	return sb->m_rect.h - 2 * sb->m_arrow.frameHeight();
}

inline SDL_Rect BarRect(const UiScrollbar *sb)
{
	SDL_Rect Tmp;
	Tmp.x = sb->m_rect.x;
	Tmp.y = static_cast<Sint16>(sb->m_rect.y + sb->m_arrow.frameHeight());
	Tmp.w = SCROLLBAR_ARROW_WIDTH,
	Tmp.h = BarHeight(sb);

	return Tmp;
}

inline SDL_Rect ThumbRect(const UiScrollbar *sb, std::size_t selected_index, std::size_t num_items)
{
	const int THUMB_OFFSET_X = 3;
	const int thumb_max_y = BarHeight(sb) - sb->m_thumb.height();
	const int thumb_y = static_cast<int>(selected_index * thumb_max_y / (num_items - 1));

	SDL_Rect Tmp;
	Tmp.x = static_cast<Sint16>(sb->m_rect.x + THUMB_OFFSET_X);
	Tmp.y = static_cast<Sint16>(sb->m_rect.y + sb->m_arrow.frameHeight() + thumb_y);
	Tmp.w = static_cast<Uint16>(sb->m_rect.w - THUMB_OFFSET_X);
	Tmp.h = static_cast<Uint16>(sb->m_thumb.height());

	return Tmp;
}

void LoadScrollBar();
void UnloadScrollBar();

} // namespace devilution
