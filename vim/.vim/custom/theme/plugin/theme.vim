" sdothum - 2016 (c) wtfpl

" Themes
" ▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂

  " The look ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁

    " .................................................................... Setup

      if exists("g:loaded_theme")
        finish
      endif
      let g:loaded_theme = 1
      let s:save_cpo = &cpo
      set cpo&vim

      " diff mode doesn't work well with reverse (block) highlighting
      let g:lightscheme = !empty(glob('~/.session/solarized')) || &diff == 1 ? 'solarized8_high' : 'flatwhite'

      " Iosevka custom compiled, with nerd-fonts awesome patches, see make_install/iosevka
      let g:source_font = 'Iosevka\'
      let g:prose_font  = 'Iosevka-proof\'
      let g:font_type   = -1                " current font setting (0) source (1) prose
      let g:font_step   = 1                 " font size increase (point size) for prose

    " .............................................................. Color codes

      " solarized colour palette (light)
      let g:rgb_0       = '#073642'         " base02 dark highlight
      let g:rgb_1       = '#dc322f'         " red
      let g:rgb_2       = '#719e07'         " green
      let g:rgb_3       = '#b58900'         " yellow
      let g:rgb_4       = '#268bd2'         " blue
      let g:rgb_5       = '#d33682'         " magenta
      let g:rgb_6       = '#2aa198'         " cyan
      let g:rgb_7       = '#eee8d5'         " base2 light highlight
      let g:rgb_8       = '#002b36'         " base03 dark bg
      let g:rgb_9       = '#cb4b16'         " orange
      let g:rgb_10      = '#586e75'         " base01 darkest grey
      let g:rgb_11      = '#657b83'         " base00 dark grey
      let g:rgb_12      = '#839496'         " base0 light grey
      let g:rgb_13      = '#6c71c4'         " violet
      let g:rgb_14      = '#93a1a1'         " base1 lightest grey
      let g:rgb_15      = '#fdf6e3'         " base3 light bg

      " flatwhite colour palette (light)
      if g:lightscheme == 'flatwhite'
        let g:rgb_15    = '#f7f3ee'         " base3 light bg
      endif

      " quantum colour palette (dark)
      let g:gray1       = '#263238'         " 023 (005f5f)
      let g:gray2       = '#2c3a41'         " 023 (005f5f)
      let g:gray3       = '#425762'         " 059 (5f5f5f)
      let g:gray4       = '#658494'         " 066 (5f8787)
      let g:gray5       = '#aebbc5'         " 146 (afafd7)
      let g:blue        = '#70ace5'         " 074 (5fafd7)
      let g:cyan        = '#69c5ce'         " 080 (5fd7d7)
      let g:green       = '#87bb7c'         " 108 (87af87)
      let g:indigo      = '#7681de'         " 104 (8787d7)
      let g:orange      = '#d7956e'         " 173 (d7875f)
      let g:purple      = '#a48add'         " 140 (af87d7)
      let g:red         = '#dd7186'         " 168 (d75f87)
      let g:yellow      = '#d5b875'         " 180 (d7af87)

      augroup theme
        autocmd!
      augroup END

  " Theme ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁

    " ...................................................... Default colorscheme

      if has("gui_running")
        " follow_the_sun on sunrise/sunset, see crontab
        if !empty(glob('~/.session/nighttime'))
          call theme#ColorScheme(1)
        else
          call theme#ColorScheme(0)
        endif
      endif

    " ............................................................ Switch colour

      nmap <silent><F8>   :call theme#LiteSwitch()<CR>
      imap <silent><F8>   <C-o>:call theme#LiteSwitch()<CR>
      vmap <silent><F8>   <C-o>:call theme#LiteSwitch()<CR>

      autocmd theme InsertEnter * call theme#LineNr('i')
      autocmd theme InsertLeave * call theme#LineNr('n')
      autocmd theme FocusGained * silent! call theme#Margin()

    " ......................................................... Switch font size

      nmap <silent><S-F9> :call theme#FontSize(g:font_type == 1 ? 0 : 1)<CR>
      imap <silent><S-F9> <C-o>:call theme#FontSize(g:font_type == 1 ? 0 : 1)<CR>
      vmap <silent><S-F9> <C-o>:call theme#FontSize(g:font_type == 1 ? 0 : 1)<CR>

      let &cpo = s:save_cpo
      unlet s:save_cpo

" theme.vim
