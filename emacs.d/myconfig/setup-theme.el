;;; package -- summary
;;; Commentary:
;; Basic setup for theming

(use-package dashboard
  :ensure
  :diminish
  :init
  (dashboard-setup-startup-hook)
  (setq dashboard-set-navigator t)
  (setq dashboard-startup-banner "~/.emacs.d/puf600X516.gif")
  :config
  (setq initial-buffer-choice (lambda () (get-buffer "*dashboard*")))
  (setq dashboard-banner-logo-title "Hi Yiwen, You are the best.")
  (setq dashboard-center-content t)
  (setq dashboard-show-shortcuts nil)
  (use-package dashboard-hackernews)
  (setq dashboard-items '(
                          (recents  . 5)
						  (projects . 5)
						  (bookmarks . 5)
                          (hackernews . 10)
                          ))
  ;; remove scratch buffer and message
  (setq initial-scratch-message "")
  (defun remove-scratch-buffer ()
  (if (get-buffer "*scratch*")
      (kill-buffer "*scratch*")))
  (add-hook 'after-change-major-mode-hook 'remove-scratch-buffer)
  (setq-default message-log-max nil)
  (kill-buffer "*Messages*")

  ;; Removes *Completions* from buffer after you've opened a file.
  (add-hook 'minibuffer-exit-hook
			'(lambda ()
			   (let ((buffer "*Completions*"))
				 (and (get-buffer buffer)
					  (kill-buffer buffer)))))

  ;; Don't show *Buffer list* when opening multiple files at the same time.
  (setq inhibit-startup-buffer-menu t)
  ;; Show only one active window when opening multiple files at the same time.
  (add-hook 'window-setup-hook 'delete-other-windows)
  )


;;; code:
(use-package powerline
  :ensure)

(use-package airline-themes
  :ensure
  :init
  :config
  (load-theme 'airline-gruvbox-dark t))

(use-package gruvbox-theme
  :ensure
  :init
  (load-theme 'gruvbox-dark-soft t))

(defun toggle-window-transparency ()
  "Cycle the frame transparency from default to transparent."
  (interactive)
  (let ((transparency 90)
        (opacity 100))
    (if (and (not (eq (frame-parameter nil 'alpha) nil))
             (< (frame-parameter nil 'alpha) opacity))
        (set-frame-parameter nil 'alpha opacity)
      (set-frame-parameter nil 'alpha transparency))))  "Cycle the frame transparency from default to transparent."

(global-set-key (kbd "C-c C-t") 'toggle-window-transparency)


(use-package diminish
  :ensure
  :config
  (diminish 'undo-tree-mode)
  (diminish 'projectile-mode)
  (diminish 'yas-minor-mode)
  (diminish 'company-mode)
  (diminish 'which-key-mode)
  (diminish 'minimap-mode)
  (diminish 'irony-mode)
  (diminish 'eldoc-mode)
  (diminish 'auto-revert-mode)
  (diminish 'abbrev-mode)
  )

(provide 'setup-theme)
;;; setup-theme.el ends here
