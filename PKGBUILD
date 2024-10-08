# Maintainer: Blurks <code@blurks.de>
pkgname=osc7cwd
pkgver=0.4
pkgrel=1
epoch=
pkgdesc="announce cwd via osc7 (built for the foot terminal emulator)"
arch=(any)
url=""
license=('unknown')
groups=()
depends=(glibc)
makedepends=(gcc)
checkdepends=()
optdepends=()
provides=()
conflicts=()
replaces=()
backup=()
options=()
install=
changelog=
source=("$pkgname-$pkgver.tar.gz")
noextract=()
sha256sums=('79fa26b723f80206bdf919335f67d7f15feb9ec2798789c8091e3715535fe794')
validpgpkeys=()

build() {
	cd "$pkgname-$pkgver"
	make
}

package() {
	cd "$pkgname-$pkgver"
	make DESTDIR="$pkgdir" install
}
