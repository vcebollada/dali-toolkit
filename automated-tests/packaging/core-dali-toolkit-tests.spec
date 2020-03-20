%define MODULE_NAME dali-toolkit
%define MODULE_LIBNAME dali-toolkit
Name:       core-%{MODULE_NAME}-tests
Summary:    Core API unit TC (%{name})
Version:    0.1
Release:    0
Group:      Development/Tools
License:    Apache-2.0 and OFL-1.1
Source0:    %{name}-%{version}.tar.gz
Requires:       dali
Requires:       dali-adaptor
Requires:       dali-toolkit
BuildRequires:  dali-integration-devel
BuildRequires:  pkgconfig(dali-core)
BuildRequires:  pkgconfig(dali)
BuildRequires:  pkgconfig(dali-toolkit)
BuildRequires:  libxml2-devel
BuildRequires:  cmake

%description
Core API unit TC (%{name})

%prep
%setup -q

%build

%define PREFIX "%{_libdir}/%{name}"

export LDFLAGS+="-Wl,--rpath=%{PREFIX} -Wl,--as-needed"
cd automated-tests
cmake . -DMODULE="%{MODULE_NAME}" -DCMAKE_INSTALL_PREFIX=%{_prefix}

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
cd automated-tests
%make_install
mkdir -p %{buildroot}/tmp/
cp %{_builddir}/%{name}-%{version}/automated-tests/scripts/add_all_smack_rule.sh %{buildroot}/tmp/
cp %{_builddir}/%{name}-%{version}/automated-tests/scripts/all_smack.rule %{buildroot}/tmp/

%post

%postun


%files
/opt/usr/bin/*
/tmp/add_all_smack_rule.sh
/tmp/all_smack.rule
%license LICENSE
